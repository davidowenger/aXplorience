#include "Common.h"

namespace NSDEVICE
{

BOMessageHandler::BOMessageHandler(Wrapper* vWrapper) :
    w(vWrapper), maKey({"MacSrc","MacDst"})
{
    mTableMessageHandler = w->mhDB->get("Message");
}

BOMessageHandler::~BOMessageHandler()
{
}

void BOMessageHandler::add(const String& vMac, nfloat vLat, nfloat vLong, const String& vTitle, const String& vType)
{
    delete add(vMac, vLat, vLong, "0", vTitle, "", "", vType);
}

DBObject* BOMessageHandler::add(const String& vMac, nfloat vLat, nfloat vLong, const String& vCategoryId, const String& vTitle, const String& vText, const String& vLink, const String& vType)
{
    vLat = vLat*k::PiOn180;
    vLong = vLong*k::PiOn180;
    nfloat z = sin(vLat);
    vLat = cos(vLat);
    return add(vMac, vLat*cos(vLong), vLat*sin(vLong), z, vCategoryId, vTitle, vText, vLink, vType);
}

DBObject* BOMessageHandler::add(const String& vMac, nfloat x, nfloat y, nfloat z, const String& vCategoryId, const String& vTitle, const String& vText, const String& vLink, const String& vType)
{
    DBObject* vDBObject = mTableMessageHandler->getInstance();
    vDBObject->set("MacSrc", vMac);
    vDBObject->set("MessageId", vDBObject->mId);
    vDBObject->set("RevSrc", 1);
    vDBObject->set("EarthCoordX", x);
    vDBObject->set("EarthCoordY", y);
    vDBObject->set("EarthCoordZ", z);
    vDBObject->set("ArchivedSrc", kFalse);
    vDBObject->set("Type", vType);
    vDBObject->set("Date", system_clock::now().time_since_epoch().count());
    vDBObject->set("Enabled", kTrue);
    vDBObject->set("Buzzed", kFalse);
    vDBObject->set("Deleted", kFalse);
    setMessage(vDBObject, vCategoryId, vTitle, vText, vLink);
    return vDBObject;
}

void BOMessageHandler::addDrop(OpUnitDB* vOpUnitDB, String packed)
{
    //FIXME: UTF8 compatibility
    nint i;
    DBCollection* vDBCollection;
    DBObject* vDBObject;
    vector<string> aValue = split(packed, String("1#"));
    nulong vSize = aValue.size();

    if (vSize >= 7) {
        vDBCollection = mTableMessageHandler->getCollection()->filter("MacSrc", aValue[0], "=")->filter("MacDst", aValue[1], "=")->filter("MessageId", aValue[2], "=");

        if (vDBCollection->count()) {
            vDBObject = vDBCollection->get(0);

            if (vDBObject->get("Type") == "1" && vDBObject->count("RevSrc") < to_long(aValue[3])) {
                vDBObject->set("RevSrc", aValue[3]);
                vDBObject->set("EarthCoordX", aValue[4]);
                vDBObject->set("EarthCoordY", aValue[5]);
                vDBObject->set("EarthCoordZ", aValue[6]);
                vDBObject->set("Date", vOpUnitDB->mcTimeStampNow);

                if (vSize == 12) {
                    // Updated INBOUND message
                    w->maMessageUpdate->add(new String("2#" + packed + "3#"));
                    //TODO: apply regex at split
                    i = 11;

                    while (--i >= 8) {
                        aValue[i] = regex_replace(aValue[i], regex("@(@|#)"), String("$1"));
                    }
                    setMessage(vDBObject, aValue[7], aValue[8], aValue[9], aValue[10]);

                    if (aValue[11] == kTrue) {
                        vDBObject->set("ArchivedSrc", kTrue);
                        vOpUnitDB->sendOp(w->mOpUnitARId, w->mNWrapper->mNKrossWrapper->mNDelta00, new OpParam((NParam)vDBObject->mId));
                    } else {
                        vDBObject->set("ArchivedSrc", kFalse);
                        vOpUnitDB->sendOp(w->mOpUnitARId, w->mNWrapper->mNKrossWrapper->mNDzeta00, new OpParam((NParam)get(vDBObject->mId)));
                    }
                } else {
                    // Alive INBOUND message
                    vOpUnitDB->sendOp(w->mOpUnitARId, w->mNWrapper->mNKrossWrapper->mNEpsilon00, new OpParam((NParam)get(vDBObject->mId)));
                }
            }
        } else if (vSize == 12) {
            // New INBOUND message
            //TODO: apply regex at split
            i = 11;

            while (--i >= 8) {
                aValue[i] = regex_replace(aValue[i], regex("@(@|#)"), String("$1"));
            }
            vDBObject = mTableMessageHandler->getInstance()->set(aValue.data(), aValue.size());
            vDBObject->set("Type", kTrue);
            vDBObject->set("Date", vOpUnitDB->mcTimeStampNow);
            vDBObject->set("Buzzed", kFalse);
            vDBObject->set("Enabled", kTrue);
            vDBObject->set("Deleted", kFalse);
            w->maMessageUpdate->add(new String("2#" + packed + "3#"));
            vOpUnitDB->sendOp(w->mOpUnitARId, w->mNWrapper->mNKrossWrapper->mNGamma00, new OpParam((NParam)vDBObject));
        }
        delete vDBCollection;
    }
}

DBObject* BOMessageHandler::addSeed(const String& vCategoryId, const String& vTitle, const String& vText, const String& vLink)
{
    nfloat* vDeviceCoord =  w->mCoordBuffer->getHead();
    return add(w->mac, vDeviceCoord[0], vDeviceCoord[1], vDeviceCoord[2], vCategoryId, vTitle, vText, vLink, kFalse);
}

void BOMessageHandler::clean()
{
    nint i;
    DBCollection* vDBCollection = mTableMessageHandler->getCollection()->filter("Type", "0", "=")->filter("Deleted", kTrue, "=");
    nint vCount = vDBCollection->count();

    for (i = 0 ; i < vCount ; ++i) {
        vDBCollection->get(i)->discardRow();
    }
    delete vDBCollection;
}

DBObject* BOMessageHandler::get(nuint id)
{
    return mTableMessageHandler->getInstance(id);
}

DBCollection* BOMessageHandler::getMessagesStatic()
{
    return mTableMessageHandler->getCollection()->filter("Id", "1", "!=")
            ->filter("Type", "2", "=");
}

DBCollection* BOMessageHandler::getMessagesDynamic()
{
    return mTableMessageHandler->getCollection()->filter("Id", "1", "!=")
            ->filter("Type", "1", "=")
            ->filter("MacDst", "", "=")
            ->filter("ArchivedSrc", kFalse, "=")
            ->filter("Deleted", kFalse, "=");
}

DBCollection* BOMessageHandler::getMessagesToBroadcast()
{
    return mTableMessageHandler->getCollection()->filter("Id", "1", "!=")
            ->filter("Type", "2", "!=");
}

DBCollection* BOMessageHandler::getMessagesToDisplay()
{
    return mTableMessageHandler->getCollection()->filter("Id", "1", "!=")
            ->filter(f("Type", "1", "!="), f("ArchivedSrc", kFalse, "="), "OR")
            ->filter("Type", "0", "!=")
            ->filter("MacDst", "", "=")
            ->filter("Deleted", kFalse, "=");
}

DBCollection* BOMessageHandler::getMessagesToList()
{
    return mTableMessageHandler->getCollection()->filter("Id", "1", "!=")
            ->filter("Type", "0", "=")
            ->filter("MacDst", "", "=")
            ->filter("Deleted", kFalse, "=");
}

DBCollection* BOMessageHandler::getMessagesToPosition()
{
    return mTableMessageHandler->getCollection()->filter("Id", "1", "!=")
            ->filter("Type", "0", "=")
            ->filter("ArchivedSrc", kFalse, "=");
}

String BOMessageHandler::pack(DBObject* vDBObject)
{
    //FIXME: UTF8 compatibility
    nuint i;
    String packed = "";
    String first = "";

    for ( i = 1 ; i <= 12 ; ++i ) {
        packed += first + regex_replace(vDBObject->maValue[i], regex("(@|#)"), String("@$1"));
        first = "1#";
    }
    return packed;
}

String BOMessageHandler::packId(DBObject* vDBObject)
{
    return
        vDBObject->maValue[1] + "1#" + vDBObject->maValue[2] + "1#" + vDBObject->maValue[3] + "1#" + vDBObject->maValue[4] + "1#" +
        vDBObject->maValue[5] + "1#" + vDBObject->maValue[6] + "1#" + vDBObject->maValue[7];
}

void BOMessageHandler::setPOI(const String& vMac, nfloat vLat, nfloat vLong, const String& vTitle, const String& vText)
{
    vLat = vLat*k::PiOn180;
    vLong = vLong*k::PiOn180;
    nfloat vEarthCoordZ = sin(vLat);
    vLat = cos(vLat);
    DBObject* vDBObject = mTableMessageHandler->getInstance();
    vDBObject->set("MacSrc", vMac);
    vDBObject->set("Title", vTitle);
    vDBObject->set("Text", vText);
    vDBObject->set("EarthCoordX", to_string(vLat*cos(vLong)));
    vDBObject->set("EarthCoordY", to_string(vLat*sin(vLong)));
    vDBObject->set("EarthCoordZ", to_string(vEarthCoordZ));
    mTableMessageHandler->free(vDBObject);
}

void BOMessageHandler::setMessage(DBObject* vDBObject, const String& id_cat, const String& title, const String& text, const String& link)
{
    vDBObject->set("CategoryId", id_cat);
    vDBObject->set("Title", title);
    vDBObject->set("Text", text);
    vDBObject->set("Link", link);
}

DBObject* BOMessageHandler::setMessage(nuint vcDBObjectId, const String& id_cat, const String& title, const String& text, const String& link)
{
    DBObject* vDBObject = mTableMessageHandler->getInstance(vcDBObjectId);
    setMessage(vDBObject, id_cat, title, text, link);
    vDBObject->set("RevSrc", vDBObject->count("RevSrc") + 1);
    return vDBObject;
}

} // End namespace
