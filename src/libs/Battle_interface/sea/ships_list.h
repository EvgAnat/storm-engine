#ifndef __SHIPS_LIST_
#define __SHIPS_LIST_

#include "..\bi_defines.h"
#include "sd2_h\VAI_ObjBase.h"

class SHIP_DESCRIBE_LIST
{
  public:
    struct SHIP_DESCR
    {
        bool isMyShip;
        bool isDead;
        long relation;
        long characterIndex;
        ATTRIBUTES *pAttr; // атрибуты корабля
        long maxHP;
        long maxSP;
        long maxCrew;
        long pictureNum;
        long selectPictureNum;
        long textureNum;
        VAI_OBJBASE *pShip;
        dword dwShipColor;

        SHIP_DESCR *next;
    };

  public:
    SHIP_DESCRIBE_LIST();
    ~SHIP_DESCRIBE_LIST();

    void Add(long mainChrIndex, long chIdx, ATTRIBUTES *pChAttr, ATTRIBUTES *pShipAttr, bool bMyShip, long relation,
             dword dwShipColor);
    SHIP_DESCR *GetMainCharacterShip()
    {
        return mainCharacter;
    }
    ATTRIBUTES *GetMainCharacterShipAttr()
    {
        return pMainShipAttr;
    }
    void Release(long charIdx);
    void ShipSink(long charIdx);
    void ReleaseAll();
    SHIP_DESCR *FindShip(long idxCharacter);
    SHIP_DESCR *GetShipRoot()
    {
        return root;
    }
    void Refresh();

  protected:
    SHIP_DESCR *root;
    SHIP_DESCR *mainCharacter;
    ATTRIBUTES *pMainShipAttr;
};

extern SHIP_DESCRIBE_LIST g_ShipList;

#endif