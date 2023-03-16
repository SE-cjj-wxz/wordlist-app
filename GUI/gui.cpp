#include "gui.h"
#include "./ui_gui.h"
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <QLibrary>
#include <vector>
#include <sstream>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <QLibrary>
#include "..\src\include\core.h"

#define MAX_WORDS_NUM 10010
#define MAX_CHAINS_NUM 20010

bool isAlpha(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); 
}

int getWords(QString text, char** words) {
    int cnt = 0;
    std::vector<char> wordBuf;

    char target;
    text += '\n';

    for (QChar qchar : text) {
        target = qchar.toLatin1();
        if (isAlpha(target)) {
            if (target >= 'A' && target <= 'Z') {
                target = target - 'A' + 'a';
            }
            wordBuf.push_back(target);
        } else {
            if (wordBuf.size() > 0) {
                wordBuf.push_back('\0');
                words[cnt] = (char *) malloc(sizeof(char) * wordBuf.size());
                for (int j = 0; j < wordBuf.size(); j++) {
                    words[cnt][j] = wordBuf[j];
                }
                wordBuf.clear();
                cnt++;
            }
        }
    }

    return cnt;
}

GUI::GUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUI)
{
    ui->setupUi(this);

    //使用 lambda 表达式进行逻辑书写

    connect(ui->uploadFile, &QPushButton::clicked, this, [=](){
        QString fileName = QFileDialog::getOpenFileName(this,
            NULL, NULL, "Text files (*.txt);; *.*");
        if (fileName.isEmpty()) {
            return;
        }
        QFile myFile(fileName);
        if (!myFile.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "文件打开失败", "你选择的文件不存在或者拒绝访问");
            return;
        }
        QTextStream in(&myFile);
        QString str = in.readAll();
        ui->inputText->setPlainText(str);
    });

    connect(ui->saveFile, &QPushButton::clicked, this, [=](){
        QString fileName = QFileDialog::getSaveFileName(this,
            NULL,  "solution.txt", "Text files (*.txt)");
        if (fileName.isEmpty()) {
            return ;
        }
        QFile myFile(fileName);
        if (!myFile.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, "文件保存失败", "你选择的文件拒绝访问");
            return;
        }
        QTextStream stream(&myFile);
        stream << ui->outputText->toPlainText();
        myFile.close();
    });    

    connect(ui->calculate, &QPushButton::clicked, this, [=](){
        char **words = (char **) malloc(sizeof(char *) * MAX_WORDS_NUM);
        char **result = (char**) malloc (sizeof (char*) * MAX_CHAINS_NUM);
        QString input = ui->inputText->toPlainText(); 

        //功能型参数
        int opt = ui->opt->currentIndex(); // 0:-n, 1:-w, 2:-c

        //辅助型参数
        char head = ui->head->currentIndex() > 0 ? ui->head->currentIndex() - 1 + 'a' : '\0';
        char tail = ui->tail->currentIndex() > 0 ? ui->tail->currentIndex() - 1 + 'a' : '\0';
        char ban = ui->ban->currentIndex() > 0 ? ui->ban->currentIndex() - 1 + 'a' : '\0';
        bool allow_circle = ui->circle->isChecked();

        if (head == ban && ban != '\0') {
            QMessageBox::warning(this, "没有匹配的结果", "-h、-j不能带相同值");
            return ;
        }

        //异常情况处理
        //未输入文本
        if (input == "") {
            QMessageBox::warning(this, "文本为空", "请输入一些单词");
            return ;
        }
        int length, ret;
        length = getWords(input, words);
        
        //链接使用核心模块库
        // HMODULE core = LoadLibraryA("core.dll");

        QString res;
        std::string ans = "";
        clock_t start, end;

        try {
            start = clock();
            if (opt == 0) {
                if (head != '\0' || tail != '\0' || allow_circle) {
                    QMessageBox::warning(this, "参数选择有误", "-n不可与-h、-t、-r共同使用");
                    return ;
                } else {
                    ret = countChains(words, length, result);
                    if (ret == 0) {
                        QMessageBox::warning(this, "没有匹配的结果", "未找到符合条件的单词链");
                        return ;
                    }
                    ans += std::to_string(ret) + '\n';
                }
            } else if (opt == 1) {
                ret = getLongestWordChain(words, length, result, head, tail, ban, allow_circle);
                if (ret <= 1) {
                    QMessageBox::warning(this, "没有匹配的结果", "未找到符合条件的单词链");
                    return ;
                }
            } else if (opt == 2) {
                ret = getLongestCharChain(words, length, result, head, tail, ban, allow_circle);
                if (ret <= 1) {
                    QMessageBox::warning(this, "没有匹配的结果", "未找到符合条件的单词链");
                    return ;
                }
            }
            end = clock();
        } catch(std::exception &e) {
            QMessageBox::warning(this, "计算时异常", e.what());
            return ;
        }

        for (int i = 0; i < ret; i++) {
            std::string s = result[i];
            ans += s + '\n';
        }
        
        res = QString::fromStdString(ans);
        ui->outputText->setPlainText(res);

        double distance = double(end - start) / 1000; //单位为s

        std::stringstream s;
        s << std::setprecision(15) << distance;
        std::string timer = "用时：" + s.str() + "s";
        ui->timer->setText(QString::fromStdString(timer));

        //释放核心链接库
        // FreeLibrary(core);
        free(words);
        free(result);
    });
}

GUI::~GUI()
{
    delete ui;
}