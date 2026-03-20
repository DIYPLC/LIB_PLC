/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbBitsToWord
 *** Description: Преобразование 16 бит в слово.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbBitsToWord_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbBitsToWord_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_word.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbBitsToWord, g_nStringIdFbBitsToWord)

const CStringDictionary::TStringId FORTE_FbBitsToWord::scmDataInputNames[] = {g_nStringIdIn0, g_nStringIdIn1, g_nStringIdIn2, g_nStringIdIn3, g_nStringIdIn4, g_nStringIdIn5, g_nStringIdIn6, g_nStringIdIn7, g_nStringIdIn8, g_nStringIdIn9, g_nStringIdIn10, g_nStringIdIn11, g_nStringIdIn12, g_nStringIdIn13, g_nStringIdIn14, g_nStringIdIn15};
const CStringDictionary::TStringId FORTE_FbBitsToWord::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbBitsToWord::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbBitsToWord::scmDataOutputTypeIds[] = {g_nStringIdWORD};
const TDataIOID FORTE_FbBitsToWord::scmEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, scmWithListDelimiter};
const TForteInt16 FORTE_FbBitsToWord::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbBitsToWord::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbBitsToWord::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbBitsToWord::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbBitsToWord::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbBitsToWord::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  16, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_FbBitsToWord::FORTE_FbBitsToWord(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_In0(false_BOOL),
    var_In1(false_BOOL),
    var_In2(false_BOOL),
    var_In3(false_BOOL),
    var_In4(false_BOOL),
    var_In5(false_BOOL),
    var_In6(false_BOOL),
    var_In7(false_BOOL),
    var_In8(false_BOOL),
    var_In9(false_BOOL),
    var_In10(false_BOOL),
    var_In11(false_BOOL),
    var_In12(false_BOOL),
    var_In13(false_BOOL),
    var_In14(false_BOOL),
    var_In15(false_BOOL),
    var_Out(0_WORD),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In0(nullptr),
    conn_In1(nullptr),
    conn_In2(nullptr),
    conn_In3(nullptr),
    conn_In4(nullptr),
    conn_In5(nullptr),
    conn_In6(nullptr),
    conn_In7(nullptr),
    conn_In8(nullptr),
    conn_In9(nullptr),
    conn_In10(nullptr),
    conn_In11(nullptr),
    conn_In12(nullptr),
    conn_In13(nullptr),
    conn_In14(nullptr),
    conn_In15(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbBitsToWord::setInitialValues() {
  var_In0 = false_BOOL;
  var_In1 = false_BOOL;
  var_In2 = false_BOOL;
  var_In3 = false_BOOL;
  var_In4 = false_BOOL;
  var_In5 = false_BOOL;
  var_In6 = false_BOOL;
  var_In7 = false_BOOL;
  var_In8 = false_BOOL;
  var_In9 = false_BOOL;
  var_In10 = false_BOOL;
  var_In11 = false_BOOL;
  var_In12 = false_BOOL;
  var_In13 = false_BOOL;
  var_In14 = false_BOOL;
  var_In15 = false_BOOL;
  var_Out = 0_WORD;
}

void FORTE_FbBitsToWord::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbBitsToWord::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbBitsToWord::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In0, conn_In0);
      readData(1, var_In1, conn_In1);
      readData(2, var_In2, conn_In2);
      readData(3, var_In3, conn_In3);
      readData(4, var_In4, conn_In4);
      readData(5, var_In5, conn_In5);
      readData(6, var_In6, conn_In6);
      readData(7, var_In7, conn_In7);
      readData(8, var_In8, conn_In8);
      readData(9, var_In9, conn_In9);
      readData(10, var_In10, conn_In10);
      readData(11, var_In11, conn_In11);
      readData(12, var_In12, conn_In12);
      readData(13, var_In13, conn_In13);
      readData(14, var_In14, conn_In14);
      readData(15, var_In15, conn_In15);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbBitsToWord::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbBitsToWord::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In0;
    case 1: return &var_In1;
    case 2: return &var_In2;
    case 3: return &var_In3;
    case 4: return &var_In4;
    case 5: return &var_In5;
    case 6: return &var_In6;
    case 7: return &var_In7;
    case 8: return &var_In8;
    case 9: return &var_In9;
    case 10: return &var_In10;
    case 11: return &var_In11;
    case 12: return &var_In12;
    case 13: return &var_In13;
    case 14: return &var_In14;
    case 15: return &var_In15;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbBitsToWord::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbBitsToWord::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbBitsToWord::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In0;
    case 1: return &conn_In1;
    case 2: return &conn_In2;
    case 3: return &conn_In3;
    case 4: return &conn_In4;
    case 5: return &conn_In5;
    case 6: return &conn_In6;
    case 7: return &conn_In7;
    case 8: return &conn_In8;
    case 9: return &conn_In9;
    case 10: return &conn_In10;
    case 11: return &conn_In11;
    case 12: return &conn_In12;
    case 13: return &conn_In13;
    case 14: return &conn_In14;
    case 15: return &conn_In15;
  }
  return nullptr;
}

CDataConnection *FORTE_FbBitsToWord::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbBitsToWord::getVarInternal(size_t) {
  return nullptr;
}

void FORTE_FbBitsToWord::alg_REQ(void) {

  #line 2 "FbBitsToWord.fbt"
  var_Out = 0_WORD;
  #line 3 "FbBitsToWord.fbt"
  if (var_In0) {
    #line 4 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 1_WORD);
  }
  #line 6 "FbBitsToWord.fbt"
  if (var_In1) {
    #line 7 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 2_WORD);
  }
  #line 9 "FbBitsToWord.fbt"
  if (var_In2) {
    #line 10 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 4_WORD);
  }
  #line 12 "FbBitsToWord.fbt"
  if (var_In3) {
    #line 13 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 8_WORD);
  }
  #line 15 "FbBitsToWord.fbt"
  if (var_In4) {
    #line 16 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 16_WORD);
  }
  #line 18 "FbBitsToWord.fbt"
  if (var_In5) {
    #line 19 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 32_WORD);
  }
  #line 21 "FbBitsToWord.fbt"
  if (var_In6) {
    #line 22 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 64_WORD);
  }
  #line 24 "FbBitsToWord.fbt"
  if (var_In7) {
    #line 25 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 128_WORD);
  }
  #line 27 "FbBitsToWord.fbt"
  if (var_In8) {
    #line 28 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 256_WORD);
  }
  #line 30 "FbBitsToWord.fbt"
  if (var_In9) {
    #line 31 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 512_WORD);
  }
  #line 33 "FbBitsToWord.fbt"
  if (var_In10) {
    #line 34 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 1024_WORD);
  }
  #line 36 "FbBitsToWord.fbt"
  if (var_In11) {
    #line 37 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 2048_WORD);
  }
  #line 39 "FbBitsToWord.fbt"
  if (var_In12) {
    #line 40 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 4096_WORD);
  }
  #line 42 "FbBitsToWord.fbt"
  if (var_In13) {
    #line 43 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 8192_WORD);
  }
  #line 45 "FbBitsToWord.fbt"
  if (var_In14) {
    #line 46 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 16384_WORD);
  }
  #line 48 "FbBitsToWord.fbt"
  if (var_In15) {
    #line 49 "FbBitsToWord.fbt"
    var_Out = func_OR<CIEC_WORD>(var_Out, 32768_WORD);
  }
}
