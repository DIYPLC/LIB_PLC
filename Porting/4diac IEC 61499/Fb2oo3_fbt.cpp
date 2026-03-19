/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Fb2oo3
 *** Description: Резервирование датчиков методом голосования.
 *** Version:
 ***     2.0: 2026-03-19/VA - LIB_PLC -
 *************************************************************************/

#include "Fb2oo3_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Fb2oo3_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/datatypes/forte_uint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_Fb2oo3, g_nStringIdFb2oo3)

const CStringDictionary::TStringId FORTE_Fb2oo3::scmDataInputNames[] = {g_nStringIdIn1, g_nStringIdIn2, g_nStringIdIn3, g_nStringIdErIn1, g_nStringIdErIn2, g_nStringIdErIn3, g_nStringIdDifMax, g_nStringIdLimMax, g_nStringIdLimMin, g_nStringIdValEr};
const CStringDictionary::TStringId FORTE_Fb2oo3::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_Fb2oo3::scmDataOutputNames[] = {g_nStringIdOut, g_nStringIdErOut, g_nStringIdEr1, g_nStringIdEr2, g_nStringIdEr3};
const CStringDictionary::TStringId FORTE_Fb2oo3::scmDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_Fb2oo3::scmEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, scmWithListDelimiter};
const TForteInt16 FORTE_Fb2oo3::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Fb2oo3::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_Fb2oo3::scmEOWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_Fb2oo3::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_Fb2oo3::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_Fb2oo3::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  10, scmDataInputNames, scmDataInputTypeIds,
  5, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_Fb2oo3::scmInternalsNames[] = {g_nStringIdState, g_nStringIdEr1Max, g_nStringIdEr2Max, g_nStringIdEr3Max, g_nStringIdEr1Min, g_nStringIdEr2Min, g_nStringIdEr3Min, g_nStringIdEr1Dif, g_nStringIdEr2Dif, g_nStringIdEr3Dif};
const CStringDictionary::TStringId FORTE_Fb2oo3::scmInternalsTypeIds[] = {g_nStringIdUINT, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL};
const SInternalVarsInformation FORTE_Fb2oo3::scmInternalVars = {10, scmInternalsNames, scmInternalsTypeIds};

const CIEC_UINT FORTE_Fb2oo3::var_const_STATE0_2oo3 = 0_UINT;
const CIEC_UINT FORTE_Fb2oo3::var_const_STATE1_1oo2 = 1_UINT;
const CIEC_UINT FORTE_Fb2oo3::var_const_STATE2_1oo2 = 2_UINT;
const CIEC_UINT FORTE_Fb2oo3::var_const_STATE3_1oo1 = 3_UINT;
const CIEC_UINT FORTE_Fb2oo3::var_const_STATE4_1oo2 = 4_UINT;
const CIEC_UINT FORTE_Fb2oo3::var_const_STATE5_1oo1 = 5_UINT;
const CIEC_UINT FORTE_Fb2oo3::var_const_STATE6_1oo1 = 6_UINT;
const CIEC_UINT FORTE_Fb2oo3::var_const_STATE7_0_ER = 7_UINT;


FORTE_Fb2oo3::FORTE_Fb2oo3(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_State(0_UINT),
    var_Er1Max(false_BOOL),
    var_Er2Max(false_BOOL),
    var_Er3Max(false_BOOL),
    var_Er1Min(false_BOOL),
    var_Er2Min(false_BOOL),
    var_Er3Min(false_BOOL),
    var_Er1Dif(false_BOOL),
    var_Er2Dif(false_BOOL),
    var_Er3Dif(false_BOOL),
    var_In1(0.0_REAL),
    var_In2(0.0_REAL),
    var_In3(0.0_REAL),
    var_ErIn1(false_BOOL),
    var_ErIn2(false_BOOL),
    var_ErIn3(false_BOOL),
    var_DifMax(5.0_REAL),
    var_LimMax(99.9_REAL),
    var_LimMin(0.1_REAL),
    var_ValEr(0.0_REAL),
    var_Out(0.0_REAL),
    var_ErOut(false_BOOL),
    var_Er1(false_BOOL),
    var_Er2(false_BOOL),
    var_Er3(false_BOOL),
    var_conn_Out(var_Out),
    var_conn_ErOut(var_ErOut),
    var_conn_Er1(var_Er1),
    var_conn_Er2(var_Er2),
    var_conn_Er3(var_Er3),
    conn_CNF(this, 0),
    conn_In1(nullptr),
    conn_In2(nullptr),
    conn_In3(nullptr),
    conn_ErIn1(nullptr),
    conn_ErIn2(nullptr),
    conn_ErIn3(nullptr),
    conn_DifMax(nullptr),
    conn_LimMax(nullptr),
    conn_LimMin(nullptr),
    conn_ValEr(nullptr),
    conn_Out(this, 0, &var_conn_Out),
    conn_ErOut(this, 1, &var_conn_ErOut),
    conn_Er1(this, 2, &var_conn_Er1),
    conn_Er2(this, 3, &var_conn_Er2),
    conn_Er3(this, 4, &var_conn_Er3) {
}

void FORTE_Fb2oo3::setInitialValues() {
  var_State = 0_UINT;
  var_Er1Max = false_BOOL;
  var_Er2Max = false_BOOL;
  var_Er3Max = false_BOOL;
  var_Er1Min = false_BOOL;
  var_Er2Min = false_BOOL;
  var_Er3Min = false_BOOL;
  var_Er1Dif = false_BOOL;
  var_Er2Dif = false_BOOL;
  var_Er3Dif = false_BOOL;
  var_In1 = 0.0_REAL;
  var_In2 = 0.0_REAL;
  var_In3 = 0.0_REAL;
  var_ErIn1 = false_BOOL;
  var_ErIn2 = false_BOOL;
  var_ErIn3 = false_BOOL;
  var_DifMax = 5.0_REAL;
  var_LimMax = 99.9_REAL;
  var_LimMin = 0.1_REAL;
  var_ValEr = 0.0_REAL;
  var_Out = 0.0_REAL;
  var_ErOut = false_BOOL;
  var_Er1 = false_BOOL;
  var_Er2 = false_BOOL;
  var_Er3 = false_BOOL;
}

void FORTE_Fb2oo3::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_Fb2oo3::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_Fb2oo3::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In1, conn_In1);
      readData(1, var_In2, conn_In2);
      readData(2, var_In3, conn_In3);
      readData(3, var_ErIn1, conn_ErIn1);
      readData(4, var_ErIn2, conn_ErIn2);
      readData(5, var_ErIn3, conn_ErIn3);
      readData(6, var_DifMax, conn_DifMax);
      readData(7, var_LimMax, conn_LimMax);
      readData(8, var_LimMin, conn_LimMin);
      readData(9, var_ValEr, conn_ValEr);
      break;
    }
    default:
      break;
  }
}

void FORTE_Fb2oo3::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      writeData(1, var_ErOut, conn_ErOut);
      writeData(2, var_Er1, conn_Er1);
      writeData(3, var_Er2, conn_Er2);
      writeData(4, var_Er3, conn_Er3);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_Fb2oo3::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In1;
    case 1: return &var_In2;
    case 2: return &var_In3;
    case 3: return &var_ErIn1;
    case 4: return &var_ErIn2;
    case 5: return &var_ErIn3;
    case 6: return &var_DifMax;
    case 7: return &var_LimMax;
    case 8: return &var_LimMin;
    case 9: return &var_ValEr;
  }
  return nullptr;
}

CIEC_ANY *FORTE_Fb2oo3::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
    case 1: return &var_ErOut;
    case 2: return &var_Er1;
    case 3: return &var_Er2;
    case 4: return &var_Er3;
  }
  return nullptr;
}

CEventConnection *FORTE_Fb2oo3::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_Fb2oo3::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In1;
    case 1: return &conn_In2;
    case 2: return &conn_In3;
    case 3: return &conn_ErIn1;
    case 4: return &conn_ErIn2;
    case 5: return &conn_ErIn3;
    case 6: return &conn_DifMax;
    case 7: return &conn_LimMax;
    case 8: return &conn_LimMin;
    case 9: return &conn_ValEr;
  }
  return nullptr;
}

CDataConnection *FORTE_Fb2oo3::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
    case 1: return &conn_ErOut;
    case 2: return &conn_Er1;
    case 3: return &conn_Er2;
    case 4: return &conn_Er3;
  }
  return nullptr;
}

CIEC_ANY *FORTE_Fb2oo3::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_State;
    case 1: return &var_Er1Max;
    case 2: return &var_Er2Max;
    case 3: return &var_Er3Max;
    case 4: return &var_Er1Min;
    case 5: return &var_Er2Min;
    case 6: return &var_Er3Min;
    case 7: return &var_Er1Dif;
    case 8: return &var_Er2Dif;
    case 9: return &var_Er3Dif;
  }
  return nullptr;
}

void FORTE_Fb2oo3::alg_REQ(void) {

  #line 3 "Fb2oo3.fbt"
  var_Er1Max = func_GE(var_In1, var_LimMax);
  #line 4 "Fb2oo3.fbt"
  var_Er2Max = func_GE(var_In2, var_LimMax);
  #line 5 "Fb2oo3.fbt"
  var_Er3Max = func_GE(var_In3, var_LimMax);
  #line 7 "Fb2oo3.fbt"
  var_Er1Min = func_LE(var_In1, var_LimMin);
  #line 8 "Fb2oo3.fbt"
  var_Er2Min = func_LE(var_In2, var_LimMin);
  #line 9 "Fb2oo3.fbt"
  var_Er3Min = func_LE(var_In3, var_LimMin);
  #line 17 "Fb2oo3.fbt"
  if (func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(var_ErIn1, 0_BOOL), func_EQ(var_ErIn2, 0_BOOL)), func_EQ(var_ErIn3, 0_BOOL)), func_EQ(var_Er1Max, 0_BOOL)), func_EQ(var_Er2Max, 0_BOOL)), func_EQ(var_Er3Max, 0_BOOL)), func_EQ(var_Er1Min, 0_BOOL)), func_EQ(var_Er2Min, 0_BOOL)), func_EQ(var_Er3Min, 0_BOOL))) {
    #line 20 "Fb2oo3.fbt"
    var_Er1Dif = func_AND<CIEC_BOOL>(func_GE(func_ABS(func_SUB<CIEC_REAL>(var_In1, var_In2)), var_DifMax), func_GE(func_ABS(func_SUB<CIEC_REAL>(var_In1, var_In3)), var_DifMax));
    #line 21 "Fb2oo3.fbt"
    var_Er2Dif = func_AND<CIEC_BOOL>(func_GE(func_ABS(func_SUB<CIEC_REAL>(var_In2, var_In1)), var_DifMax), func_GE(func_ABS(func_SUB<CIEC_REAL>(var_In2, var_In3)), var_DifMax));
    #line 22 "Fb2oo3.fbt"
    var_Er3Dif = func_AND<CIEC_BOOL>(func_GE(func_ABS(func_SUB<CIEC_REAL>(var_In3, var_In1)), var_DifMax), func_GE(func_ABS(func_SUB<CIEC_REAL>(var_In3, var_In2)), var_DifMax));
  }
  #line 26 "Fb2oo3.fbt"
  var_Er1 = func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_ErIn1, var_Er1Max), var_Er1Min), var_Er1Dif);
  #line 27 "Fb2oo3.fbt"
  var_Er2 = func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_ErIn2, var_Er2Max), var_Er2Min), var_Er2Dif);
  #line 28 "Fb2oo3.fbt"
  var_Er3 = func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_ErIn3, var_Er3Max), var_Er3Min), var_Er3Dif);
  #line 31 "Fb2oo3.fbt"
  var_ErOut = func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(var_Er1, var_Er2), var_Er3);
  #line 33 "Fb2oo3.fbt"
  if (func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(0_BOOL, var_Er1), func_EQ(0_BOOL, var_Er2)), func_EQ(0_BOOL, var_Er3))) {
    #line 34 "Fb2oo3.fbt"
    var_State = 0_UINT;
  }
  #line 36 "Fb2oo3.fbt"
  if (func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(0_BOOL, var_Er1), func_EQ(0_BOOL, var_Er2)), func_EQ(1_BOOL, var_Er3))) {
    #line 37 "Fb2oo3.fbt"
    var_State = 1_UINT;
  }
  #line 39 "Fb2oo3.fbt"
  if (func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(0_BOOL, var_Er1), func_EQ(1_BOOL, var_Er2)), func_EQ(0_BOOL, var_Er3))) {
    #line 40 "Fb2oo3.fbt"
    var_State = 2_UINT;
  }
  #line 42 "Fb2oo3.fbt"
  if (func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(0_BOOL, var_Er1), func_EQ(1_BOOL, var_Er2)), func_EQ(1_BOOL, var_Er3))) {
    #line 43 "Fb2oo3.fbt"
    var_State = 3_UINT;
  }
  #line 45 "Fb2oo3.fbt"
  if (func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(1_BOOL, var_Er1), func_EQ(0_BOOL, var_Er2)), func_EQ(0_BOOL, var_Er3))) {
    #line 46 "Fb2oo3.fbt"
    var_State = 4_UINT;
  }
  #line 48 "Fb2oo3.fbt"
  if (func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(1_BOOL, var_Er1), func_EQ(0_BOOL, var_Er2)), func_EQ(1_BOOL, var_Er3))) {
    #line 49 "Fb2oo3.fbt"
    var_State = 5_UINT;
  }
  #line 51 "Fb2oo3.fbt"
  if (func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(1_BOOL, var_Er1), func_EQ(1_BOOL, var_Er2)), func_EQ(0_BOOL, var_Er3))) {
    #line 52 "Fb2oo3.fbt"
    var_State = 6_UINT;
  }
  #line 54 "Fb2oo3.fbt"
  if (func_AND<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(1_BOOL, var_Er1), func_EQ(1_BOOL, var_Er2)), func_EQ(1_BOOL, var_Er3))) {
    #line 55 "Fb2oo3.fbt"
    var_State = 7_UINT;
  }
  #line 73 "Fb2oo3.fbt"
  if (auto st_lv_synthetic_0 = var_State; false) {
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE0_2oo3)) {
    #line 81 "Fb2oo3.fbt"
    if (func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_GE(var_In1, var_In2), func_LE(var_In1, var_In3)), func_AND<CIEC_BOOL>(func_GE(var_In1, var_In3), func_LE(var_In1, var_In2)))) {
      #line 82 "Fb2oo3.fbt"
      var_Out = var_In1;
    }
    #line 84 "Fb2oo3.fbt"
    if (func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_GE(var_In2, var_In3), func_LE(var_In2, var_In1)), func_AND<CIEC_BOOL>(func_GE(var_In2, var_In1), func_LE(var_In2, var_In3)))) {
      #line 85 "Fb2oo3.fbt"
      var_Out = var_In2;
    }
    #line 87 "Fb2oo3.fbt"
    if (func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_GE(var_In3, var_In2), func_LE(var_In3, var_In1)), func_AND<CIEC_BOOL>(func_GE(var_In3, var_In1), func_LE(var_In3, var_In2)))) {
      #line 88 "Fb2oo3.fbt"
      var_Out = var_In3;
    }
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE1_1oo2)) {
    #line 95 "Fb2oo3.fbt"
    var_Out = var_In1;
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE2_1oo2)) {
    #line 101 "Fb2oo3.fbt"
    var_Out = var_In1;
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE3_1oo1)) {
    #line 107 "Fb2oo3.fbt"
    var_Out = var_In1;
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE4_1oo2)) {
    #line 113 "Fb2oo3.fbt"
    var_Out = var_In2;
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE5_1oo1)) {
    #line 119 "Fb2oo3.fbt"
    var_Out = var_In2;
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE6_1oo1)) {
    #line 125 "Fb2oo3.fbt"
    var_Out = var_In3;
  } else if (func_EQ(st_lv_synthetic_0, var_const_STATE7_0_ER)) {
    #line 133 "Fb2oo3.fbt"
    var_Out = var_ValEr;
  } else {
    #line 136 "Fb2oo3.fbt"
    var_State = var_const_STATE7_0_ER;
  }
}
