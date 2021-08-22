//
// Created by timas on 12.08.2021.
//

#ifndef COMPANY_STRUCTURE_PARSER_HPP
#define COMPANY_STRUCTURE_PARSER_HPP

#include <QDebug>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QXmlDefaultHandler>
#include <QXmlAttributes>

class CompanyParser: public QXmlDefaultHandler {
private:
    QString currentText;

    QTreeWidget* treeWidget;

    QTreeWidgetItem* currentItem;

    int iteration = 0;

    QString parsing_title;

    QString temp_text;

public:
    CompanyParser(QTreeWidget* tree, const QString &);

    bool startElement(const QString &, const QString &, const QString &, const QXmlAttributes &);

    bool characters(const QString &);

    bool endElement(const QString &, const QString &, const QString &);

    bool fatalError(const QXmlParseException &exception);
};

#endif //COMPANY_STRUCTURE_PARSER_HPP
