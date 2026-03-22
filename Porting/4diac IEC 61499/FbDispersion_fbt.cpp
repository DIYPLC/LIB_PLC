/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbDispersion
 *** Description: Дисперсия PV.
 *** Version:
 ***     1.1: 2026-03-22/VA - LIB_PLC -
 *************************************************************************/

#include "FbDispersion_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbDispersion_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_int.h"
#include "core/datatypes/forte_real.h"
#include "core/datatypes/forte_sint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbDispersion, g_nStringIdFbDispersion)

const CStringDictionary::TStringId FORTE_FbDispersion::scmDataInputNames[] = {g_nStringIdIn};
const CStringDictionary::TStringId FORTE_FbDispersion::scmDataInputTypeIds[] = {g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbDispersion::scmDataOutputNames[] = {g_nStringIdVariance, g_nStringIdDeviation, g_nStringIdMean};
const CStringDictionary::TStringId FORTE_FbDispersion::scmDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const TDataIOID FORTE_FbDispersion::scmEIWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbDispersion::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbDispersion::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbDispersion::scmEOWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_FbDispersion::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbDispersion::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbDispersion::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  1, scmDataInputNames, scmDataInputTypeIds,
  3, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbDispersion::scmInternalsNames[] = {g_nStringIdBuffer1, g_nStringIdSummator};
const CStringDictionary::TStringId FORTE_FbDispersion::scmInternalsTypeIds[] = {g_nStringIdARRAY, static_cast<CStringDictionary::TStringId>(0), static_cast<CStringDictionary::TStringId>(99), g_nStringIdREAL, g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbDispersion::scmInternalVars = {2, scmInternalsNames, scmInternalsTypeIds};

const CIEC_INT FORTE_FbDispersion::var_const_NUMBER = 99_INT;


FORTE_FbDispersion::FORTE_FbDispersion(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Buffer1(CIEC_ARRAY_FIXED<CIEC_REAL, 0, 99>{}),
    var_Summator(0.0_REAL),
    var_In(0.0_REAL),
    var_Variance(0.0_REAL),
    var_Deviation(0.0_REAL),
    var_Mean(0.0_REAL),
    var_conn_Variance(var_Variance),
    var_conn_Deviation(var_Deviation),
    var_conn_Mean(var_Mean),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_Variance(this, 0, &var_conn_Variance),
    conn_Deviation(this, 1, &var_conn_Deviation),
    conn_Mean(this, 2, &var_conn_Mean) {
}

void FORTE_FbDispersion::setInitialValues() {
  var_Buffer1 = CIEC_ARRAY_FIXED<CIEC_REAL, 0, 99>{};
  var_Summator = 0.0_REAL;
  var_In = 0.0_REAL;
  var_Variance = 0.0_REAL;
  var_Deviation = 0.0_REAL;
  var_Mean = 0.0_REAL;
}

void FORTE_FbDispersion::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbDispersion::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbDispersion::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbDispersion::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Variance, conn_Variance);
      writeData(1, var_Deviation, conn_Deviation);
      writeData(2, var_Mean, conn_Mean);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbDispersion::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbDispersion::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Variance;
    case 1: return &var_Deviation;
    case 2: return &var_Mean;
  }
  return nullptr;
}

CEventConnection *FORTE_FbDispersion::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbDispersion::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
  }
  return nullptr;
}

CDataConnection *FORTE_FbDispersion::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Variance;
    case 1: return &conn_Deviation;
    case 2: return &conn_Mean;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbDispersion::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Buffer1;
    case 1: return &var_Summator;
  }
  return nullptr;
}

void FORTE_FbDispersion::alg_REQ(void) {
  CIEC_INT st_lv_Counter1 = 0_INT;

  #line 8 "FbDispersion.fbt"
  for (auto st_lv_synthetic_0 : ST_FOR_ITER<CIEC_INT, CIEC_INT>(st_lv_Counter1, var_const_NUMBER, 1_INT, -1_INT)) {
    #line 9 "FbDispersion.fbt"
    var_Buffer1[st_lv_Counter1] = var_Buffer1[func_SUB<CIEC_INT>(st_lv_Counter1, 1_INT)];
  }
  #line 11 "FbDispersion.fbt"
  var_Buffer1[0_SINT] = var_In;
  #line 14 "FbDispersion.fbt"
  var_Summator = 0.0_REAL;
  #line 15 "FbDispersion.fbt"
  for (auto st_lv_synthetic_1 : ST_FOR_ITER<CIEC_INT, CIEC_INT>(st_lv_Counter1, 0_INT, var_const_NUMBER, 1_INT)) {
    #line 16 "FbDispersion.fbt"
    var_Summator = func_ADD<CIEC_REAL>(var_Summator, var_Buffer1[st_lv_Counter1]);
  }
  #line 18 "FbDispersion.fbt"
  var_Mean = func_DIV<CIEC_REAL>(var_Summator, func_INT_TO_REAL(func_ADD<CIEC_INT>(var_const_NUMBER, 1_INT)));
  #line 21 "FbDispersion.fbt"
  var_Summator = 0.0_REAL;
  #line 22 "FbDispersion.fbt"
  for (auto st_lv_synthetic_2 : ST_FOR_ITER<CIEC_INT, CIEC_INT>(st_lv_Counter1, 0_INT, var_const_NUMBER, 1_INT)) {
    #line 23 "FbDispersion.fbt"
    var_Summator = func_ADD<CIEC_REAL>(var_Summator, func_MUL<CIEC_REAL>(func_SUB<CIEC_REAL>(var_Buffer1[st_lv_Counter1], var_Mean), func_SUB<CIEC_REAL>(var_Buffer1[st_lv_Counter1], var_Mean)));
  }
  #line 25 "FbDispersion.fbt"
  var_Variance = func_DIV<CIEC_REAL>(var_Summator, func_INT_TO_REAL(func_ADD<CIEC_INT>(var_const_NUMBER, 1_INT)));
  #line 28 "FbDispersion.fbt"
  var_Deviation = func_SQRT(var_Variance);
}
