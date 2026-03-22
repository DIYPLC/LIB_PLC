/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbFilterM
 *** Description: Фильтр медианный.
 *** Version:
 ***     1.1: 2026-03-22/VA - LIB_PLC -
 *************************************************************************/

#include "FbFilterM_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbFilterM_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_dint.h"
#include "core/datatypes/forte_int.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbFilterM, g_nStringIdFbFilterM)

const CStringDictionary::TStringId FORTE_FbFilterM::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdSize, g_nStringIdTs_in, g_nStringIdTs_ms, g_nStringIdReset};
const CStringDictionary::TStringId FORTE_FbFilterM::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdINT, g_nStringIdDINT, g_nStringIdDINT, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbFilterM::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbFilterM::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbFilterM::scmEIWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_FbFilterM::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbFilterM::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbFilterM::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbFilterM::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbFilterM::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbFilterM::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  5, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbFilterM::scmInternalsNames[] = {g_nStringIdTimerTs, g_nStringIdSize_prev, g_nStringIdOld_i, g_nStringIdInputArray, g_nStringIdTimeArray};
const CStringDictionary::TStringId FORTE_FbFilterM::scmInternalsTypeIds[] = {g_nStringIdDINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdARRAY, static_cast<CStringDictionary::TStringId>(0), static_cast<CStringDictionary::TStringId>(64), g_nStringIdREAL, g_nStringIdARRAY, static_cast<CStringDictionary::TStringId>(0), static_cast<CStringDictionary::TStringId>(64), g_nStringIdINT};
const SInternalVarsInformation FORTE_FbFilterM::scmInternalVars = {5, scmInternalsNames, scmInternalsTypeIds};

const CIEC_INT FORTE_FbFilterM::var_const_NUMBER = 64_INT;


FORTE_FbFilterM::FORTE_FbFilterM(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_TimerTs(0_DINT),
    var_Size_prev(0_INT),
    var_Old_i(0_INT),
    var_InputArray(CIEC_ARRAY_FIXED<CIEC_REAL, 0, 64>{}),
    var_TimeArray(CIEC_ARRAY_FIXED<CIEC_INT, 0, 64>{}),
    var_In(0.0_REAL),
    var_Size(16_INT),
    var_Ts_in(1000_DINT),
    var_Ts_ms(100_DINT),
    var_Reset(false_BOOL),
    var_Out(0.0_REAL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_Size(nullptr),
    conn_Ts_in(nullptr),
    conn_Ts_ms(nullptr),
    conn_Reset(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbFilterM::setInitialValues() {
  var_TimerTs = 0_DINT;
  var_Size_prev = 0_INT;
  var_Old_i = 0_INT;
  var_InputArray = CIEC_ARRAY_FIXED<CIEC_REAL, 0, 64>{};
  var_TimeArray = CIEC_ARRAY_FIXED<CIEC_INT, 0, 64>{};
  var_In = 0.0_REAL;
  var_Size = 16_INT;
  var_Ts_in = 1000_DINT;
  var_Ts_ms = 100_DINT;
  var_Reset = false_BOOL;
  var_Out = 0.0_REAL;
}

void FORTE_FbFilterM::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbFilterM::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbFilterM::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_Size, conn_Size);
      readData(2, var_Ts_in, conn_Ts_in);
      readData(3, var_Ts_ms, conn_Ts_ms);
      readData(4, var_Reset, conn_Reset);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbFilterM::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbFilterM::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_Size;
    case 2: return &var_Ts_in;
    case 3: return &var_Ts_ms;
    case 4: return &var_Reset;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbFilterM::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbFilterM::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbFilterM::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_Size;
    case 2: return &conn_Ts_in;
    case 3: return &conn_Ts_ms;
    case 4: return &conn_Reset;
  }
  return nullptr;
}

CDataConnection *FORTE_FbFilterM::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbFilterM::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_TimerTs;
    case 1: return &var_Size_prev;
    case 2: return &var_Old_i;
    case 3: return &var_InputArray;
    case 4: return &var_TimeArray;
  }
  return nullptr;
}

void FORTE_FbFilterM::alg_REQ(void) {
  CIEC_BOOL st_lv_FlagRunCode = 0_BOOL;
  CIEC_INT st_lv_Adr_max = 0_INT;
  CIEC_INT st_lv_i = 0_INT;
  CIEC_INT st_lv_j = 0_INT;
  CIEC_REAL st_lv_TempValue = 0_REAL;
  CIEC_INT st_lv_TempTime = 0_INT;

  #line 38 "FbFilterM.fbt"
  st_lv_Adr_max = func_SUB<CIEC_INT>(var_Size, 1_INT);
  #line 40 "FbFilterM.fbt"
  if (func_GE(var_Size, var_const_NUMBER)) {
    #line 41 "FbFilterM.fbt"
    st_lv_Adr_max = func_SUB<CIEC_INT>(var_const_NUMBER, 2_INT);
  }
  #line 44 "FbFilterM.fbt"
  if (func_LE(var_Size, 5_INT)) {
    #line 45 "FbFilterM.fbt"
    st_lv_Adr_max = 4_INT;
  }
  #line 50 "FbFilterM.fbt"
  if (func_GE(var_Ts_ms, var_Ts_in)) {
    #line 51 "FbFilterM.fbt"
    var_TimerTs = 0_DINT;
    #line 52 "FbFilterM.fbt"
    st_lv_FlagRunCode = true_BOOL;
  }
  else {
    #line 55 "FbFilterM.fbt"
    if (func_GE(var_TimerTs, var_Ts_in)) {
      #line 56 "FbFilterM.fbt"
      var_TimerTs = 0_DINT;
      #line 57 "FbFilterM.fbt"
      st_lv_FlagRunCode = true_BOOL;
    }
    else {
      #line 59 "FbFilterM.fbt"
      var_TimerTs = func_ADD<CIEC_DINT>(var_TimerTs, var_Ts_ms);
      #line 60 "FbFilterM.fbt"
      st_lv_FlagRunCode = false_BOOL;
    }
  }
  #line 68 "FbFilterM.fbt"
  if (func_OR<CIEC_BOOL>(var_Reset, func_NE(var_Size, var_Size_prev))) {
    #line 70 "FbFilterM.fbt"
    for (auto st_lv_synthetic_0 : ST_FOR_ITER<CIEC_INT, CIEC_INT>(st_lv_i, 0_INT, st_lv_Adr_max, 1_INT)) {
      #line 72 "FbFilterM.fbt"
      var_InputArray[st_lv_i] = var_In;
      #line 74 "FbFilterM.fbt"
      var_TimeArray[st_lv_i] = st_lv_i;
    }
    #line 77 "FbFilterM.fbt"
    var_Old_i = st_lv_Adr_max;
  }
  #line 92 "FbFilterM.fbt"
  if (func_AND<CIEC_BOOL>(st_lv_FlagRunCode, func_NE(var_Size, 0_INT))) {
    #line 94 "FbFilterM.fbt"
    for (auto st_lv_synthetic_1 : ST_FOR_ITER<CIEC_INT, CIEC_INT>(st_lv_i, 0_INT, st_lv_Adr_max, 1_INT)) {
      #line 96 "FbFilterM.fbt"
      if (func_EQ(var_TimeArray[st_lv_i], st_lv_Adr_max)) {
        #line 98 "FbFilterM.fbt"
        var_TimeArray[st_lv_i] = 0_INT;
      }
      else {
        #line 101 "FbFilterM.fbt"
        var_TimeArray[st_lv_i] = func_ADD<CIEC_INT>(var_TimeArray[st_lv_i], 1_INT);
        #line 103 "FbFilterM.fbt"
        if (func_EQ(var_TimeArray[st_lv_i], st_lv_Adr_max)) {
          #line 106 "FbFilterM.fbt"
          var_Old_i = st_lv_i;
        }
      }
    }
    #line 113 "FbFilterM.fbt"
    var_InputArray[var_Old_i] = var_In;
    #line 143 "FbFilterM.fbt"
    st_lv_i = 0_INT;
    #line 144 "FbFilterM.fbt"
    while (func_LT(st_lv_i, st_lv_Adr_max)) {
      #line 145 "FbFilterM.fbt"
      st_lv_j = 0_INT;
      #line 146 "FbFilterM.fbt"
      while (func_LT(st_lv_j, func_SUB<CIEC_INT>(st_lv_Adr_max, st_lv_i))) {
        #line 147 "FbFilterM.fbt"
        if (func_GT(var_InputArray[st_lv_j], var_InputArray[func_ADD<CIEC_INT>(st_lv_j, 1_INT)])) {
          #line 149 "FbFilterM.fbt"
          st_lv_TempValue = var_InputArray[st_lv_j];
          #line 150 "FbFilterM.fbt"
          var_InputArray[st_lv_j] = var_InputArray[func_ADD<CIEC_INT>(st_lv_j, 1_INT)];
          #line 151 "FbFilterM.fbt"
          var_InputArray[func_ADD<CIEC_INT>(st_lv_j, 1_INT)] = st_lv_TempValue;
          #line 153 "FbFilterM.fbt"
          st_lv_TempTime = var_TimeArray[st_lv_j];
          #line 154 "FbFilterM.fbt"
          var_TimeArray[st_lv_j] = var_TimeArray[func_ADD<CIEC_INT>(st_lv_j, 1_INT)];
          #line 155 "FbFilterM.fbt"
          var_TimeArray[func_ADD<CIEC_INT>(st_lv_j, 1_INT)] = st_lv_TempTime;
        }
        #line 157 "FbFilterM.fbt"
        st_lv_j = func_ADD<CIEC_INT>(st_lv_j, 1_INT);
      }
      #line 159 "FbFilterM.fbt"
      st_lv_i = func_ADD<CIEC_INT>(st_lv_i, 1_INT);
    }
  }
  #line 174 "FbFilterM.fbt"
  if (func_NE(var_Size, 0_INT)) {
    #line 175 "FbFilterM.fbt"
    var_Out = var_InputArray[func_DIV<CIEC_INT>(st_lv_Adr_max, 2_INT)];
  }
  else {
    #line 177 "FbFilterM.fbt"
    var_Out = var_In;
  }
  #line 182 "FbFilterM.fbt"
  var_Size_prev = var_Size;
}
