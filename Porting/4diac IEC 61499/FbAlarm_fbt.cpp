/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbAlarm
 *** Description: Блок предупреждений.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbAlarm_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbAlarm_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/datatypes/forte_udint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbAlarm, g_nStringIdFbAlarm)

const CStringDictionary::TStringId FORTE_FbAlarm::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdLevelHi, g_nStringIdLevelLo, g_nStringIdTimeDelay, g_nStringIdTs_ms};
const CStringDictionary::TStringId FORTE_FbAlarm::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdUDINT, g_nStringIdUDINT};
const CStringDictionary::TStringId FORTE_FbAlarm::scmDataOutputNames[] = {g_nStringIdAlarmHi, g_nStringIdAlarmLo};
const CStringDictionary::TStringId FORTE_FbAlarm::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_FbAlarm::scmEIWith[] = {0, 1, 2, 3, 4, scmWithListDelimiter};
const TForteInt16 FORTE_FbAlarm::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbAlarm::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbAlarm::scmEOWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_FbAlarm::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbAlarm::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbAlarm::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  5, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbAlarm::scmInternalsNames[] = {g_nStringId_AlarmHi, g_nStringId_AlarmLo, g_nStringIdTimer1, g_nStringIdTimer2};
const CStringDictionary::TStringId FORTE_FbAlarm::scmInternalsTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdUDINT, g_nStringIdUDINT};
const SInternalVarsInformation FORTE_FbAlarm::scmInternalVars = {4, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbAlarm::FORTE_FbAlarm(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var__AlarmHi(false_BOOL),
    var__AlarmLo(false_BOOL),
    var_Timer1(0_UDINT),
    var_Timer2(0_UDINT),
    var_In(0.0_REAL),
    var_LevelHi(0.0_REAL),
    var_LevelLo(0.0_REAL),
    var_TimeDelay(0_UDINT),
    var_Ts_ms(0_UDINT),
    var_AlarmHi(false_BOOL),
    var_AlarmLo(false_BOOL),
    var_conn_AlarmHi(var_AlarmHi),
    var_conn_AlarmLo(var_AlarmLo),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_LevelHi(nullptr),
    conn_LevelLo(nullptr),
    conn_TimeDelay(nullptr),
    conn_Ts_ms(nullptr),
    conn_AlarmHi(this, 0, &var_conn_AlarmHi),
    conn_AlarmLo(this, 1, &var_conn_AlarmLo) {
}

void FORTE_FbAlarm::setInitialValues() {
  var__AlarmHi = false_BOOL;
  var__AlarmLo = false_BOOL;
  var_Timer1 = 0_UDINT;
  var_Timer2 = 0_UDINT;
  var_In = 0.0_REAL;
  var_LevelHi = 0.0_REAL;
  var_LevelLo = 0.0_REAL;
  var_TimeDelay = 0_UDINT;
  var_Ts_ms = 0_UDINT;
  var_AlarmHi = false_BOOL;
  var_AlarmLo = false_BOOL;
}

void FORTE_FbAlarm::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbAlarm::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbAlarm::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_LevelHi, conn_LevelHi);
      readData(2, var_LevelLo, conn_LevelLo);
      readData(3, var_TimeDelay, conn_TimeDelay);
      readData(4, var_Ts_ms, conn_Ts_ms);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbAlarm::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_AlarmHi, conn_AlarmHi);
      writeData(1, var_AlarmLo, conn_AlarmLo);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbAlarm::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_LevelHi;
    case 2: return &var_LevelLo;
    case 3: return &var_TimeDelay;
    case 4: return &var_Ts_ms;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbAlarm::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_AlarmHi;
    case 1: return &var_AlarmLo;
  }
  return nullptr;
}

CEventConnection *FORTE_FbAlarm::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbAlarm::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_LevelHi;
    case 2: return &conn_LevelLo;
    case 3: return &conn_TimeDelay;
    case 4: return &conn_Ts_ms;
  }
  return nullptr;
}

CDataConnection *FORTE_FbAlarm::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_AlarmHi;
    case 1: return &conn_AlarmLo;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbAlarm::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var__AlarmHi;
    case 1: return &var__AlarmLo;
    case 2: return &var_Timer1;
    case 3: return &var_Timer2;
  }
  return nullptr;
}

void FORTE_FbAlarm::alg_REQ(void) {

  #line 3 "FbAlarm.fbt"
  var__AlarmHi = func_GE(var_In, var_LevelHi);
  #line 6 "FbAlarm.fbt"
  if (func_GT(var_TimeDelay, 0_UDINT)) {
    #line 7 "FbAlarm.fbt"
    if (var__AlarmHi) {
      #line 8 "FbAlarm.fbt"
      if (var_AlarmHi) {
        #line 9 "FbAlarm.fbt"
        var_AlarmHi = true_BOOL;
      }
      else {
        #line 11 "FbAlarm.fbt"
        if (func_GE(var_Timer1, var_TimeDelay)) {
          #line 12 "FbAlarm.fbt"
          var_AlarmHi = true_BOOL;
        }
        else {
          #line 14 "FbAlarm.fbt"
          var_AlarmHi = false_BOOL;
          #line 15 "FbAlarm.fbt"
          var_Timer1 = func_ADD<CIEC_UDINT>(var_Timer1, var_Ts_ms);
        }
      }
    }
    else {
      #line 19 "FbAlarm.fbt"
      var_AlarmHi = false_BOOL;
      #line 20 "FbAlarm.fbt"
      var_Timer1 = 0_UDINT;
    }
  }
  else {
    #line 23 "FbAlarm.fbt"
    var_AlarmHi = var__AlarmHi;
    #line 24 "FbAlarm.fbt"
    var_Timer1 = 0_UDINT;
  }
  #line 28 "FbAlarm.fbt"
  var__AlarmLo = func_LE(var_In, var_LevelLo);
  #line 31 "FbAlarm.fbt"
  if (func_GT(var_TimeDelay, 0_UDINT)) {
    #line 32 "FbAlarm.fbt"
    if (var__AlarmLo) {
      #line 33 "FbAlarm.fbt"
      if (var_AlarmLo) {
        #line 34 "FbAlarm.fbt"
        var_AlarmLo = true_BOOL;
      }
      else {
        #line 36 "FbAlarm.fbt"
        if (func_GE(var_Timer2, var_TimeDelay)) {
          #line 37 "FbAlarm.fbt"
          var_AlarmLo = true_BOOL;
        }
        else {
          #line 39 "FbAlarm.fbt"
          var_AlarmLo = false_BOOL;
          #line 40 "FbAlarm.fbt"
          var_Timer2 = func_ADD<CIEC_UDINT>(var_Timer2, var_Ts_ms);
        }
      }
    }
    else {
      #line 44 "FbAlarm.fbt"
      var_AlarmLo = false_BOOL;
      #line 45 "FbAlarm.fbt"
      var_Timer2 = 0_UDINT;
    }
  }
  else {
    #line 48 "FbAlarm.fbt"
    var_AlarmLo = var__AlarmLo;
    #line 49 "FbAlarm.fbt"
    var_Timer2 = 0_UDINT;
  }
}
