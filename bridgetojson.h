#ifndef BRIDGETOJSON_H
#define BRIDGETOJSON_H

#include <QString>
#include <QJsonArray>
#include <QJsonObject>

class BridgeToJson
{
public:
    struct Contact {
        QString name;
        QString phone;
        QString email;
    };
    static QJsonArray contactsToJson(const QList<Contact> &contacts);
    static QList<Contact> jsonToContacts(const QJsonArray &jsonArray);
    static bool saveContactsToJsonFile(const QList<Contact> &contacts, const QString &fileName);
    static QList<Contact> loadContactsFromJsonFile(const QString &fileName);
};

#endif // BRIDGETOJSON_H
