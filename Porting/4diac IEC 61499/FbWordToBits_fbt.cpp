/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbWordToBits
 *** Description: Преобразование слова в 16 бит.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbWordToBits_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbWordToBits_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_byte.h"
#include "core/datatypes/forte_dword.h"
#include "core/datatypes/forte_word.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbWordToBits, g_nStringIdFbWordToBits)

const CStringDictionary::TStringId FORTE_FbWordToBits::scmDataInputNames[] = {g_nStringIdIn};
const CStringDictionary::TStringId FORTE_FbWordToBits::scmDataInputTypeIds[] = {g_nStringIdWORD};
const CStringDictionary::TStringId FORTE_FbWordToBits::scmDataOutputNames[] = {g_nStringIdOut0, g_nStringIdOut1, g_nStringIdOut2, g_nStringIdOut3, g_nStringIdOut4, g_nStringIdOut5, g_nStringIdOut6, g_nStringIdOut7, g_nStringIdOut8, g_nStringIdOut9, g_nStringIdOut10, g_nStringIdOut11, g_nStringIdOut12, g_nStringIdOut13, g_nStringIdOut14, g_nStringIdOut15};
const CStringDictionary::TStringId FORTE_FbWordToBits::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_FbWordToBits::scmEIWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbWordToBits::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbWordToBits::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbWordToBits::scmEOWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, scmWithListDelimiter};
const TForteInt16 FORTE_FbWordToBits::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbWordToBits::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbWordToBits::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  1, scmDataInputNames, scmDataInputTypeIds,
  16, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_FbWordToBits::FORTE_FbWordToBits(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_In(0_WORD),
    var_Out0(false_BOOL),
    var_Out1(false_BOOL),
    var_Out2(false_BOOL),
    var_Out3(false_BOOL),
    var_Out4(false_BOOL),
    var_Out5(false_BOOL),
    var_Out6(false_BOOL),
    var_Out7(false_BOOL),
    var_Out8(false_BOOL),
    var_Out9(false_BOOL),
    var_Out10(false_BOOL),
    var_Out11(false_BOOL),
    var_Out12(false_BOOL),
    var_Out13(false_BOOL),
    var_Out14(false_BOOL),
    var_Out15(false_BOOL),
    var_conn_Out0(var_Out0),
    var_conn_Out1(var_Out1),
    var_conn_Out2(var_Out2),
    var_conn_Out3(var_Out3),
    var_conn_Out4(var_Out4),
    var_conn_Out5(var_Out5),
    var_conn_Out6(var_Out6),
    var_conn_Out7(var_Out7),
    var_conn_Out8(var_Out8),
    var_conn_Out9(var_Out9),
    var_conn_Out10(var_Out10),
    var_conn_Out11(var_Out11),
    var_conn_Out12(var_Out12),
    var_conn_Out13(var_Out13),
    var_conn_Out14(var_Out14),
    var_conn_Out15(var_Out15),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_Out0(this, 0, &var_conn_Out0),
    conn_Out1(this, 1, &var_conn_Out1),
    conn_Out2(this, 2, &var_conn_Out2),
    conn_Out3(this, 3, &var_conn_Out3),
    conn_Out4(this, 4, &var_conn_Out4),
    conn_Out5(this, 5, &var_conn_Out5),
    conn_Out6(this, 6, &var_conn_Out6),
    conn_Out7(this, 7, &var_conn_Out7),
    conn_Out8(this, 8, &var_conn_Out8),
    conn_Out9(this, 9, &var_conn_Out9),
    conn_Out10(this, 10, &var_conn_Out10),
    conn_Out11(this, 11, &var_conn_Out11),
    conn_Out12(this, 12, &var_conn_Out12),
    conn_Out13(this, 13, &var_conn_Out13),
    conn_Out14(this, 14, &var_conn_Out14),
    conn_Out15(this, 15, &var_conn_Out15) {
}

void FORTE_FbWordToBits::setInitialValues() {
  var_In = 0_WORD;
  var_Out0 = false_BOOL;
  var_Out1 = false_BOOL;
  var_Out2 = false_BOOL;
  var_Out3 = false_BOOL;
  var_Out4 = false_BOOL;
  var_Out5 = false_BOOL;
  var_Out6 = false_BOOL;
  var_Out7 = false_BOOL;
  var_Out8 = false_BOOL;
  var_Out9 = false_BOOL;
  var_Out10 = false_BOOL;
  var_Out11 = false_BOOL;
  var_Out12 = false_BOOL;
  var_Out13 = false_BOOL;
  var_Out14 = false_BOOL;
  var_Out15 = false_BOOL;
}

void FORTE_FbWordToBits::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbWordToBits::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbWordToBits::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbWordToBits::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out0, conn_Out0);
      writeData(1, var_Out1, conn_Out1);
      writeData(2, var_Out2, conn_Out2);
      writeData(3, var_Out3, conn_Out3);
      writeData(4, var_Out4, conn_Out4);
      writeData(5, var_Out5, conn_Out5);
      writeData(6, var_Out6, conn_Out6);
      writeData(7, var_Out7, conn_Out7);
      writeData(8, var_Out8, conn_Out8);
      writeData(9, var_Out9, conn_Out9);
      writeData(10, var_Out10, conn_Out10);
      writeData(11, var_Out11, conn_Out11);
      writeData(12, var_Out12, conn_Out12);
      writeData(13, var_Out13, conn_Out13);
      writeData(14, var_Out14, conn_Out14);
      writeData(15, var_Out15, conn_Out15);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbWordToBits::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbWordToBits::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out0;
    case 1: return &var_Out1;
    case 2: return &var_Out2;
    case 3: return &var_Out3;
    case 4: return &var_Out4;
    case 5: return &var_Out5;
    case 6: return &var_Out6;
    case 7: return &var_Out7;
    case 8: return &var_Out8;
    case 9: return &var_Out9;
    case 10: return &var_Out10;
    case 11: return &var_Out11;
    case 12: return &var_Out12;
    case 13: return &var_Out13;
    case 14: return &var_Out14;
    case 15: return &var_Out15;
  }
  return nullptr;
}

CEventConnection *FORTE_FbWordToBits::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbWordToBits::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
  }
  return nullptr;
}

CDataConnection *FORTE_FbWordToBits::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out0;
    case 1: return &conn_Out1;
    case 2: return &conn_Out2;
    case 3: return &conn_Out3;
    case 4: return &conn_Out4;
    case 5: return &conn_Out5;
    case 6: return &conn_Out6;
    case 7: return &conn_Out7;
    case 8: return &conn_Out8;
    case 9: return &conn_Out9;
    case 10: return &conn_Out10;
    case 11: return &conn_Out11;
    case 12: return &conn_Out12;
    case 13: return &conn_Out13;
    case 14: return &conn_Out14;
    case 15: return &conn_Out15;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbWordToBits::getVarInternal(size_t) {
  return nullptr;
}

void FORTE_FbWordToBits::alg_REQ(void) {

  #line 3 "FbWordToBits.fbt"
  var_Out0 = func_NE(func_AND<CIEC_WORD>(var_In, 1_BYTE), 0_WORD);
  #line 4 "FbWordToBits.fbt"
  var_Out1 = func_NE(func_AND<CIEC_WORD>(var_In, 2_BYTE), 0_WORD);
  #line 5 "FbWordToBits.fbt"
  var_Out2 = func_NE(func_AND<CIEC_WORD>(var_In, 4_BYTE), 0_WORD);
  #line 6 "FbWordToBits.fbt"
  var_Out3 = func_NE(func_AND<CIEC_WORD>(var_In, 8_BYTE), 0_WORD);
  #line 7 "FbWordToBits.fbt"
  var_Out4 = func_NE(func_AND<CIEC_WORD>(var_In, 16_BYTE), 0_WORD);
  #line 8 "FbWordToBits.fbt"
  var_Out5 = func_NE(func_AND<CIEC_WORD>(var_In, 32_BYTE), 0_WORD);
  #line 9 "FbWordToBits.fbt"
  var_Out6 = func_NE(func_AND<CIEC_WORD>(var_In, 64_BYTE), 0_WORD);
  #line 10 "FbWordToBits.fbt"
  var_Out7 = func_NE(func_AND<CIEC_WORD>(var_In, 128_BYTE), 0_WORD);
  #line 11 "FbWordToBits.fbt"
  var_Out8 = func_NE(func_AND<CIEC_WORD>(var_In, 256_WORD), 0_WORD);
  #line 12 "FbWordToBits.fbt"
  var_Out9 = func_NE(func_AND<CIEC_WORD>(var_In, 512_WORD), 0_WORD);
  #line 13 "FbWordToBits.fbt"
  var_Out10 = func_NE(func_AND<CIEC_WORD>(var_In, 1024_WORD), 0_WORD);
  #line 14 "FbWordToBits.fbt"
  var_Out11 = func_NE(func_AND<CIEC_WORD>(var_In, 2048_WORD), 0_WORD);
  #line 15 "FbWordToBits.fbt"
  var_Out12 = func_NE(func_AND<CIEC_WORD>(var_In, 4096_WORD), 0_WORD);
  #line 16 "FbWordToBits.fbt"
  var_Out13 = func_NE(func_AND<CIEC_WORD>(var_In, 8192_WORD), 0_WORD);
  #line 17 "FbWordToBits.fbt"
  var_Out14 = func_NE(func_AND<CIEC_WORD>(var_In, 16384_WORD), 0_WORD);
  #line 18 "FbWordToBits.fbt"
  var_Out15 = func_NE(func_AND<CIEC_WORD>(var_In, 32768_WORD), 0_DWORD);
}
