
#include "../include/global.h"
#include "../include/ingame_trades.h"
#include "../include/link.h"
#include "../include/pokemon.h"
#include "../include/string_util.h"
#include "../include/trade.h"
#include "config.h"

#include "../include/new/build_pokemon.h"
#include "../include/new/rom_locs.h"
#include "../include/new/Vanilla_functions_battle.h"

#include "../include/constants/region_map_sections.h"
#include "../include/constants/species.h"
#include "../include/constants/items.h"

extern struct TradeAnimationResources * sTradeData;

extern u8 gText_InGameTrade_MrLine[];
extern u8 gText_InGameTrade_Reyley[];
extern u8 gText_InGameTrade_Litleffing[];
extern u8 gText_InGameTrade_Dontae[];
extern u8 gText_InGameTrade_Gastbug[];
extern u8 gText_InGameTrade_Saige[];
extern u8 gText_InGameTrade_Minimie[];
extern u8 gText_InGameTrade_Elyssa[];
extern u8 gText_InGameTrade_Sunkela[];
extern u8 gText_InGameTrade_Turner[];
extern u8 gText_InGameTrade_Herapinny[];
extern u8 gText_InGameTrade_Haden[];
extern u8 gText_InGameTrade_Aerosculin[];
extern u8 gText_InGameTrade_Clifton[];
extern u8 gText_InGameTrade_Nymbuto[];
extern u8 gText_InGameTrade_Norma[];
extern u8 gText_InGameTrade_Omanellor[];
extern u8 gText_InGameTrade_Garett[];
/* More Trades */
extern u8 gText_InGameTrade_Gaspar[];
extern u8 gText_InGameTrade_Mindy[];
extern u8 gText_InGameTrade_Weave[];
extern u8 gText_InGameTrade_Damien[];

static const struct InGameTrade sInGameTrades[] = {
    // REYLEY (Route 2)
    [INGAME_TRADE_MR_LINE] = 
    {
        .nickname = gText_InGameTrade_MrLine,
        .species = SPECIES_MAREEP, // Mr. Line (179)
        .ivs = {22, 11, 24, 20, 26, 22},
        .abilityNum = 0,
        .otId = 1703,
        .conditions = {5, 5, 5, 30, 5},
        .personality = 0x00009cae,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Reyley,
        .otGender = MALE,
        .nature = NATURE_TIMID,
        .requestedSpecies = SPECIES_DODRIO // Mareebra (85)
    }, 
    // Dontae (Cerulean City)
    [INGAME_TRADE_LITLEFFING] = 
    {
        .nickname = gText_InGameTrade_Litleffing,
        .species = SPECIES_TYPHLOSION, // Litleffing (157)
        .ivs = {22, 21, 11, 27, 21, 31},
        .abilityNum = 0,
        .otId = 54213,
        .conditions = {5, 30, 5, 5, 5},
        .personality = 0x498a2e1d,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Dontae,
        .otGender = MALE,
        .nature = NATURE_MILD,
        .requestedSpecies = SPECIES_NINETALES // Nidoswine (38)
    }, 
    // SAIGE
    [INGAME_TRADE_GASTBUG] = 
    {
        .nickname = gText_InGameTrade_Gastbug,
        .species = SPECIES_GYARADOS, // Gastbug (130)
        .ivs = {15, 30, 27, 30, 12, 31},
        .abilityNum = 0,
        .otId = 63184,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x4c970b89,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Saige,
        .otGender = FEMALE,
        .nature = NATURE_HARDY,
        .requestedSpecies = SPECIES_DUGTRIO // Zubaskull (51)
    }, 
    // ELYSSA
    [INGAME_TRADE_MINIMIE] = 
    {
        .nickname = gText_InGameTrade_Minimie,
        .species = SPECIES_TOGETIC, // Minimie (176)
        .ivs = {20, 25, 21, 24, 15, 20},
        .abilityNum = 0,
        .otId = 8810,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x151943d7,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Elyssa,
        .otGender = MALE,
        .nature = NATURE_ADAMANT,
        .requestedSpecies = SPECIES_VILEPLUME // Nineturne (45)
    }, 
    // TURNER
    [INGAME_TRADE_SUNKELA] = 
    {
        .nickname = gText_InGameTrade_Sunkela,
        .species = SPECIES_LEDIAN, // Sunkela (166)
        .ivs = {22, 29, 31, 5, 29, 30},
        .abilityNum = 0,
        .otId = 13637,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00eeca15,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Turner,
        .otGender = MALE,
        .nature = NATURE_ADAMANT,
        .requestedSpecies = SPECIES_ZUBAT // Cleffip (41)
    }, 
    // HADEN
    [INGAME_TRADE_HERAPINNY] = 
    {
        .nickname = gText_InGameTrade_Herapinny,
        .species = SPECIES_HOOTHOOT, // Herapinny (163)
        .ivs = {30, 27, 14, 31, 14, 11},
        .abilityNum = 0,
        .otId = 1239,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x451308ab,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Haden,
        .otGender = MALE,
        .nature = NATURE_IMPISH,
        .requestedSpecies = SPECIES_BUTTERFREE // Butterlure (12)
    }, 
    // CLIFTON
    [INGAME_TRADE_AEROSCULIN] = 
    {
        .nickname = gText_InGameTrade_Aerosculin,
        .species = SPECIES_TEDDIURSA, // Aerosculin (219)
        .ivs = {19, 31, 19, 31, 21, 23},
        .abilityNum = 1,
        .otId = 50298,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x06341016,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Clifton,
        .otGender = MALE,
        .nature = NATURE_TIMID,
        .requestedSpecies = SPECIES_PIDGEOT // Pidgeggron (18)
    }, 
    // NORMA
    [INGAME_TRADE_NYMBUTO] = 
    {
        .nickname = gText_InGameTrade_Nymbuto,
        .species = SPECIES_URSARING, // Nymbuto (217)
        .ivs = {8, 14, 9, 31, 31, 30},
        .abilityNum = 0,
        .otId = 60042,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x5c77ecfa,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Norma,
        .otGender = FEMALE,
        .nature = NATURE_JOLLY,
        .requestedSpecies = SPECIES_OMASTAR // Kinglnaw (139)
    },
    // GARETT
    [INGAME_TRADE_OMANELLOR] = 
    {
        .nickname = gText_InGameTrade_Omanellor,
        .species = SPECIES_SNEASEL, // Omanellor (215)
        .ivs = {29, 17, 31, 8, 21, 19},
        .abilityNum = 0,
        .otId = 9853,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x482cac89,
        .heldItem = ITEM_NONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Garett,
        .otGender = MALE,
        .nature = NATURE_BOLD,
        .requestedSpecies = SPECIES_MAGNETON // Silcowhirl (82)
    },

    /* More Trades */

    // MINDY
    [INGAME_TRADE_HAUNTER] = 
    {
        .nickname = gText_InGameTrade_Gaspar,
        .species = SPECIES_HAUNTER,
        .ivs = {24, 0, 17, 0, 0, 14},
        .abilityNum = 0,
        .otId = 19248,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x482cac89,
        .heldItem = ITEM_EVERSTONE,
        .mailNum = 255,
        .otName = gText_InGameTrade_Mindy,
        .otGender = FEMALE,
        .nature = NATURE_IMPISH,
        .requestedSpecies = SPECIES_VOLTORB
    },
    // DAMIEN
    [INGAME_TRADE_WEAVILE] = 
    {
        .nickname = gText_InGameTrade_Weave,
        .species = SPECIES_WEAVILE,
        .ivs = {31, 31, 31, 31, 9, 31},
        .abilityNum = 0,
        .otId = 17244,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x482cac89,
        .heldItem = ITEM_LIFE_ORB,
        .mailNum = 255,
        .otName = gText_InGameTrade_Damien,
        .otGender = MALE,
        .nature = NATURE_JOLLY,
        .requestedSpecies = SPECIES_SNEASLER
    }
};

extern const u16 sInGameTradeMailMessages[][10];

static void GetInGameTradeMail(struct MailStructDaycare * mail, const struct InGameTrade * inGameTrade)
{
    int i;
    for (i = 0; i < MAIL_WORDS_COUNT; i++)
        mail->words[i] = sInGameTradeMailMessages[inGameTrade->mailNum][i];
    StringCopy(mail->playerName, inGameTrade->otName);
    mail->trainerId[0] = inGameTrade->otId >> 24;
    mail->trainerId[1] = inGameTrade->otId >> 16;
    mail->trainerId[2] = inGameTrade->otId >> 8;
    mail->trainerId[3] = inGameTrade->otId;
    mail->species = inGameTrade->species;
    mail->itemId = inGameTrade->heldItem;
}

void TradeBufferOTnameAndNicknames(void)
{
    u8 nickname[20];
    u8 mpId;
    const struct InGameTrade * inGameTrade;
    if (sTradeData->isLinkTrade)
    {
        mpId = GetMultiplayerId();
        StringCopy(gStringVar1, gLinkPlayers[mpId ^ 1].name);
        GetMonData(&gEnemyParty[gSelectedTradeMonPositions[1] % 6], MON_DATA_NICKNAME, nickname);
        StringCopy_Nickname(gStringVar3, nickname);
        GetMonData(&gPlayerParty[gSelectedTradeMonPositions[0]], MON_DATA_NICKNAME, nickname);
        StringCopy_Nickname(gStringVar2, nickname);
    }
    else
    {
        inGameTrade = &sInGameTrades[Var8004];
        StringCopy(gStringVar1, inGameTrade->otName);
        StringCopy_Nickname(gStringVar3, inGameTrade->nickname);
        GetMonData(&gPlayerParty[Var8005], MON_DATA_NICKNAME, nickname);
        StringCopy_Nickname(gStringVar2, nickname);
    }
}

u16 GetInGameTradeSpeciesInfo(void)
{
    // Populates gStringVar1 with the name of the requested species and
    // gStringVar2 with the name of the offered species.
    // Returns the requested species.
    const struct InGameTrade * inGameTrade = &sInGameTrades[Var8004];
    StringCopy(gStringVar1, gSpeciesNames[inGameTrade->requestedSpecies]);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
    return inGameTrade->requestedSpecies;
}

void BufferInGameTradeMonName(void)
{
    // Populates gStringVar1 with the nickname of the sent Pokemon and
    // gStringVar2 with the name of the offered species.
    u8 nickname[30];
    const struct InGameTrade * inGameTrade = &sInGameTrades[Var8004];
    GetMonData(&gPlayerParty[Var8005], MON_DATA_NICKNAME, nickname);
    StringCopy_Nickname(gStringVar1, nickname);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
}

void CreateInGameTradePokemonInternal(u8 playerSlot, u8 inGameTradeIdx)
{
    const struct InGameTrade * inGameTrade = &sInGameTrades[inGameTradeIdx];
    u8 level = (inGameTradeIdx == INGAME_TRADE_HAUNTER) ? 27 : GetMonData(&gPlayerParty[playerSlot], MON_DATA_LEVEL, 0);
    struct MailStructDaycare mail;
    u8 metLocation = METLOC_IN_GAME_TRADE;
    struct Pokemon * tradeMon = &gEnemyParty[0];
    u8 mailNum;
    u8 hauntHP = 67;
    CreateMon(tradeMon, inGameTrade->species, level, 32, TRUE, inGameTrade->personality, TRUE, inGameTrade->otId);
    SetMonData(tradeMon, MON_DATA_HP_IV, &inGameTrade->ivs[0]);
    SetMonData(tradeMon, MON_DATA_ATK_IV, &inGameTrade->ivs[1]);
    SetMonData(tradeMon, MON_DATA_DEF_IV, &inGameTrade->ivs[2]);
    SetMonData(tradeMon, MON_DATA_SPEED_IV, &inGameTrade->ivs[3]);
    SetMonData(tradeMon, MON_DATA_SPATK_IV, &inGameTrade->ivs[4]);
    SetMonData(tradeMon, MON_DATA_SPDEF_IV, &inGameTrade->ivs[5]);
    SetMonData(tradeMon, MON_DATA_NICKNAME, inGameTrade->nickname);
    SetMonData(tradeMon, MON_DATA_OT_NAME, inGameTrade->otName);
    SetMonData(tradeMon, MON_DATA_OT_GENDER, &inGameTrade->otGender);
    SetMonData(tradeMon, MON_DATA_BEAUTY, &inGameTrade->conditions[1]);
    SetMonData(tradeMon, MON_DATA_CUTE, &inGameTrade->conditions[2]);
    SetMonData(tradeMon, MON_DATA_COOL, &inGameTrade->conditions[0]);
    SetMonData(tradeMon, MON_DATA_SMART, &inGameTrade->conditions[3]);
    SetMonData(tradeMon, MON_DATA_TOUGH, &inGameTrade->conditions[4]);
    SetMonData(tradeMon, MON_DATA_MET_LOCATION, &metLocation);
    if(inGameTradeIdx == INGAME_TRADE_HAUNTER)
        SetMonData(tradeMon, MON_DATA_HP, &hauntHP);
    GiveMonNatureAndAbility(tradeMon, inGameTrade->nature, inGameTrade->abilityNum, IsMonShiny(tradeMon), TRUE, TRUE);
    mailNum = 0;
    if (inGameTrade->heldItem != ITEM_NONE)
    {
        if (ItemIsMail(inGameTrade->heldItem))
        {
            GetInGameTradeMail(&mail, inGameTrade);
            gLinkPartnerMail[0] = mail;
            SetMonData(tradeMon, MON_DATA_MAIL, &mailNum);
            SetMonData(tradeMon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
        else
        {
            SetMonData(tradeMon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
    }
    CalculateMonStats(&gEnemyParty[0]);
}