﻿/*Copyright 2017 hyperchain.net  (Hyper Block Chain)
/*
/*Distributed under the MIT software license, see the accompanying
/*file COPYING or https://opensource.org/licenses/MIT.
/*
/*Permission is hereby granted, free of charge, to any person obtaining a copy of this 
/*software and associated documentation files (the "Software"), to deal in the Software
/*without restriction, including without limitation the rights to use, copy, modify, merge,
/*publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
/*to whom the Software is furnished to do so, subject to the following conditions:
/*
/*The above copyright notice and this permission notice shall be included in all copies or
/*substantial portions of the Software.
/*
/*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
/*INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
/*PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
/*FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
/*OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/*DEALINGS IN THE SOFTWARE.
*/

#ifndef CHAIN_BROWSER_CHANNEL_H
#define CHAIN_BROWSER_CHANNEL_H

#include <QObject>
#include <QVariantMap>
#include <QVariant>
#include <QSharedPointer>

class block_detail_dlg;

class chain_browser_channel : public QObject
{
    Q_OBJECT
public:
    explicit chain_browser_channel(QObject *parent = 0);

public slots:
    void onHtmlReady();

    void search(QString key);

    void showDetail(QVariantMap generalInfo);

    int  getConfirmingNum();

    void getLastBlockInfo();

    void setLanguage(int lang);


signals:
    void sigUpdateGeneralInfo(QVariantMap generalInfo);
    void sigSearchResult(QVariant resultList);
    void sigShowLastBlockInfo(QVariant generalInfo);

    void sigChangeLang(int lang);

public slots:

private:
    QSharedPointer<block_detail_dlg> detailDlg_;
};

#endif // CHAIN_BROWSER_CHANNEL_H