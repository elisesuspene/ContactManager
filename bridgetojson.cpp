#include "bridgetojson.h"

#include <QFile>
#include <QJsonDocument>

QJsonArray BridgeToJson::contactsToJson(const QList<Contact> &contacts) {
    QJsonArray jsonArray;
    for (const auto &contact : contacts) {
        QJsonObject obj;
        obj["name"] = contact.name;
        obj["phone"] = contact.phone;
        obj["email"] = contact.email;
        jsonArray.append(obj);
    }
    return jsonArray;
}

QList<BridgeToJson::Contact> BridgeToJson::jsonToContacts(const QJsonArray &jsonArray) {
    QList<Contact> contacts;
    for (const auto &val : jsonArray) {
        QJsonObject obj = val.toObject();
        Contact contact;
        contact.name = obj["name"].toString();
        contact.phone = obj["phone"].toString();
        contact.email = obj["email"].toString();
        contacts.append(contact);
    }
    return contacts;
}

bool BridgeToJson::saveContactsToJsonFile(const QList<Contact> &contacts, const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    QJsonArray jsonArray = contactsToJson(contacts);
    QJsonDocument doc(jsonArray);
    file.write(doc.toJson());
    return true;
}

QList<BridgeToJson::Contact> BridgeToJson::loadContactsFromJsonFile(const QString &fileName) {
    QList<Contact> contacts;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return contacts;
    }
    QJsonArray jsonArray = QJsonDocument::fromJson(file.readAll()).array();
    contacts = jsonToContacts(jsonArray);
    return contacts;
}
