/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbSoftPWM
 *** Description: ШИМ генератор двухканальный.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbSoftPWM_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbSoftPWM_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbSoftPWM, g_nStringIdFbSoftPWM)

const CStringDictionary::TStringId FORTE_FbSoftPWM::scmDataInputNames[] = {g_nStringIdDutyCucle, g_nStringIdPeriodPositive, g_nStringIdPeriodNegative, g_nStringIdDBMAX, g_nStringIdDBMIN, g_nStringIdTs};
const CStringDictionary::TStringId FORTE_FbSoftPWM::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbSoftPWM::scmDataOutputNames[] = {g_nStringIdPWMPOS, g_nStringIdPWMNEG};
const CStringDictionary::TStringId FORTE_FbSoftPWM::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_FbSoftPWM::scmEIWith[] = {0, 1, 2, 3, 4, 5, scmWithListDelimiter};
const TForteInt16 FORTE_FbSoftPWM::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbSoftPWM::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbSoftPWM::scmEOWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_FbSoftPWM::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbSoftPWM::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbSoftPWM::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  6, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbSoftPWM::scmInternalsNames[] = {g_nStringIdTimerPositive, g_nStringIdTimerNegative, g_nStringIdPercent, g_nStringIdTimePulsePositive, g_nStringIdTimePulseNegative};
const CStringDictionary::TStringId FORTE_FbSoftPWM::scmInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbSoftPWM::scmInternalVars = {5, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbSoftPWM::FORTE_FbSoftPWM(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_TimerPositive(0.0_REAL),
    var_TimerNegative(0.0_REAL),
    var_Percent(0.0_REAL),
    var_TimePulsePositive(0.0_REAL),
    var_TimePulseNegative(0.0_REAL),
    var_DutyCucle(50.0_REAL),
    var_PeriodPositive(10.0_REAL),
    var_PeriodNegative(10.0_REAL),
    var_DBMAX(0.001_REAL),
    var_DBMIN(-0.001_REAL),
    var_Ts(0.1_REAL),
    var_PWMPOS(false_BOOL),
    var_PWMNEG(false_BOOL),
    var_conn_PWMPOS(var_PWMPOS),
    var_conn_PWMNEG(var_PWMNEG),
    conn_CNF(this, 0),
    conn_DutyCucle(nullptr),
    conn_PeriodPositive(nullptr),
    conn_PeriodNegative(nullptr),
    conn_DBMAX(nullptr),
    conn_DBMIN(nullptr),
    conn_Ts(nullptr),
    conn_PWMPOS(this, 0, &var_conn_PWMPOS),
    conn_PWMNEG(this, 1, &var_conn_PWMNEG) {
}

void FORTE_FbSoftPWM::setInitialValues() {
  var_TimerPositive = 0.0_REAL;
  var_TimerNegative = 0.0_REAL;
  var_Percent = 0.0_REAL;
  var_TimePulsePositive = 0.0_REAL;
  var_TimePulseNegative = 0.0_REAL;
  var_DutyCucle = 50.0_REAL;
  var_PeriodPositive = 10.0_REAL;
  var_PeriodNegative = 10.0_REAL;
  var_DBMAX = 0.001_REAL;
  var_DBMIN = -0.001_REAL;
  var_Ts = 0.1_REAL;
  var_PWMPOS = false_BOOL;
  var_PWMNEG = false_BOOL;
}

void FORTE_FbSoftPWM::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbSoftPWM::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbSoftPWM::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_DutyCucle, conn_DutyCucle);
      readData(1, var_PeriodPositive, conn_PeriodPositive);
      readData(2, var_PeriodNegative, conn_PeriodNegative);
      readData(3, var_DBMAX, conn_DBMAX);
      readData(4, var_DBMIN, conn_DBMIN);
      readData(5, var_Ts, conn_Ts);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbSoftPWM::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_PWMPOS, conn_PWMPOS);
      writeData(1, var_PWMNEG, conn_PWMNEG);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbSoftPWM::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_DutyCucle;
    case 1: return &var_PeriodPositive;
    case 2: return &var_PeriodNegative;
    case 3: return &var_DBMAX;
    case 4: return &var_DBMIN;
    case 5: return &var_Ts;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbSoftPWM::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_PWMPOS;
    case 1: return &var_PWMNEG;
  }
  return nullptr;
}

CEventConnection *FORTE_FbSoftPWM::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbSoftPWM::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_DutyCucle;
    case 1: return &conn_PeriodPositive;
    case 2: return &conn_PeriodNegative;
    case 3: return &conn_DBMAX;
    case 4: return &conn_DBMIN;
    case 5: return &conn_Ts;
  }
  return nullptr;
}

CDataConnection *FORTE_FbSoftPWM::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_PWMPOS;
    case 1: return &conn_PWMNEG;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbSoftPWM::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_TimerPositive;
    case 1: return &var_TimerNegative;
    case 2: return &var_Percent;
    case 3: return &var_TimePulsePositive;
    case 4: return &var_TimePulseNegative;
  }
  return nullptr;
}

void FORTE_FbSoftPWM::alg_REQ(void) {

  #line 3 "FbSoftPWM.fbt"
  if (func_AND<CIEC_BOOL>(func_LT(var_DBMIN, var_DutyCucle), func_LT(var_DutyCucle, var_DBMAX))) {
    #line 4 "FbSoftPWM.fbt"
    var_Percent = 0.0_REAL;
  }
  else {
    #line 6 "FbSoftPWM.fbt"
    var_Percent = var_DutyCucle;
  }
  #line 10 "FbSoftPWM.fbt"
  if (func_GE(var_Percent, 100.0_REAL)) {
    #line 11 "FbSoftPWM.fbt"
    var_Percent = 100.0_REAL;
  }
  #line 13 "FbSoftPWM.fbt"
  if (func_LE(var_Percent, -100.0_REAL)) {
    #line 14 "FbSoftPWM.fbt"
    var_Percent = -100.0_REAL;
  }
  #line 18 "FbSoftPWM.fbt"
  if (func_GT(var_Percent, 0.0_REAL)) {
    #line 19 "FbSoftPWM.fbt"
    var_PWMNEG = false_BOOL;
    #line 20 "FbSoftPWM.fbt"
    var_TimerNegative = 0.0_REAL;
    #line 21 "FbSoftPWM.fbt"
    var_TimePulsePositive = func_MUL<CIEC_REAL>(func_MUL<CIEC_REAL>(var_PeriodPositive, var_Percent), 0.01_REAL);
    #line 22 "FbSoftPWM.fbt"
    if (func_LE(var_TimerPositive, var_TimePulsePositive)) {
      #line 23 "FbSoftPWM.fbt"
      var_PWMPOS = true_BOOL;
    }
    else {
      #line 25 "FbSoftPWM.fbt"
      var_PWMPOS = false_BOOL;
    }
    #line 27 "FbSoftPWM.fbt"
    var_TimerPositive = func_ADD<CIEC_REAL>(var_TimerPositive, var_Ts);
    #line 28 "FbSoftPWM.fbt"
    if (func_GE(var_TimerPositive, var_PeriodPositive)) {
      #line 29 "FbSoftPWM.fbt"
      var_TimerPositive = 0.0_REAL;
    }
  }
  #line 34 "FbSoftPWM.fbt"
  if (func_LT(var_Percent, 0.0_REAL)) {
    #line 35 "FbSoftPWM.fbt"
    var_PWMPOS = false_BOOL;
    #line 36 "FbSoftPWM.fbt"
    var_TimerPositive = 0.0_REAL;
    #line 37 "FbSoftPWM.fbt"
    var_TimePulseNegative = func_MUL<CIEC_REAL>(func_MUL<CIEC_REAL>(var_PeriodNegative, var_Percent), -0.01_REAL);
    #line 38 "FbSoftPWM.fbt"
    if (func_LE(var_TimerNegative, var_TimePulseNegative)) {
      #line 39 "FbSoftPWM.fbt"
      var_PWMNEG = true_BOOL;
    }
    else {
      #line 41 "FbSoftPWM.fbt"
      var_PWMNEG = false_BOOL;
    }
    #line 43 "FbSoftPWM.fbt"
    var_TimerNegative = func_ADD<CIEC_REAL>(var_TimerNegative, var_Ts);
    #line 44 "FbSoftPWM.fbt"
    if (func_GE(var_TimerNegative, var_PeriodNegative)) {
      #line 45 "FbSoftPWM.fbt"
      var_TimerNegative = 0.0_REAL;
    }
  }
  #line 50 "FbSoftPWM.fbt"
  if (func_EQ(var_Percent, 0.0_REAL)) {
    #line 51 "FbSoftPWM.fbt"
    var_PWMPOS = false_BOOL;
    #line 52 "FbSoftPWM.fbt"
    var_PWMNEG = false_BOOL;
    #line 53 "FbSoftPWM.fbt"
    var_TimerPositive = 0.0_REAL;
    #line 54 "FbSoftPWM.fbt"
    var_TimerNegative = 0.0_REAL;
  }
}
