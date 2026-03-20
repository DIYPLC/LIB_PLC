/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbSimMotorGear
 *** Description: Виртуальный МЭО для отладки шагового регулятора.
 *** Version:
 ***     0.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbSimMotorGear_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbSimMotorGear_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbSimMotorGear, g_nStringIdFbSimMotorGear)

const CStringDictionary::TStringId FORTE_FbSimMotorGear::scmDataInputNames[] = {g_nStringIdCmdOpen, g_nStringIdCmdClose, g_nStringIdTimeOpen, g_nStringIdTimeClose, g_nStringIdTs, g_nStringIdReset};
const CStringDictionary::TStringId FORTE_FbSimMotorGear::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbSimMotorGear::scmDataOutputNames[] = {g_nStringIdPosition, g_nStringIdSensorOpen, g_nStringIdSensorClose};
const CStringDictionary::TStringId FORTE_FbSimMotorGear::scmDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_FbSimMotorGear::scmEIWith[] = {0, 1, 2, 3, 4, 5, scmWithListDelimiter};
const TForteInt16 FORTE_FbSimMotorGear::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbSimMotorGear::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbSimMotorGear::scmEOWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_FbSimMotorGear::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbSimMotorGear::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbSimMotorGear::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  6, scmDataInputNames, scmDataInputTypeIds,
  3, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbSimMotorGear::scmInternalsNames[] = {g_nStringIdSpeedPos, g_nStringIdSpeedNeg};
const CStringDictionary::TStringId FORTE_FbSimMotorGear::scmInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbSimMotorGear::scmInternalVars = {2, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbSimMotorGear::FORTE_FbSimMotorGear(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_SpeedPos(0.0_REAL),
    var_SpeedNeg(0.0_REAL),
    var_CmdOpen(false_BOOL),
    var_CmdClose(false_BOOL),
    var_TimeOpen(60.0_REAL),
    var_TimeClose(50.0_REAL),
    var_Ts(0.1_REAL),
    var_Reset(false_BOOL),
    var_Position(0.0_REAL),
    var_SensorOpen(false_BOOL),
    var_SensorClose(false_BOOL),
    var_conn_Position(var_Position),
    var_conn_SensorOpen(var_SensorOpen),
    var_conn_SensorClose(var_SensorClose),
    conn_CNF(this, 0),
    conn_CmdOpen(nullptr),
    conn_CmdClose(nullptr),
    conn_TimeOpen(nullptr),
    conn_TimeClose(nullptr),
    conn_Ts(nullptr),
    conn_Reset(nullptr),
    conn_Position(this, 0, &var_conn_Position),
    conn_SensorOpen(this, 1, &var_conn_SensorOpen),
    conn_SensorClose(this, 2, &var_conn_SensorClose) {
}

void FORTE_FbSimMotorGear::setInitialValues() {
  var_SpeedPos = 0.0_REAL;
  var_SpeedNeg = 0.0_REAL;
  var_CmdOpen = false_BOOL;
  var_CmdClose = false_BOOL;
  var_TimeOpen = 60.0_REAL;
  var_TimeClose = 50.0_REAL;
  var_Ts = 0.1_REAL;
  var_Reset = false_BOOL;
  var_Position = 0.0_REAL;
  var_SensorOpen = false_BOOL;
  var_SensorClose = false_BOOL;
}

void FORTE_FbSimMotorGear::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbSimMotorGear::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbSimMotorGear::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_CmdOpen, conn_CmdOpen);
      readData(1, var_CmdClose, conn_CmdClose);
      readData(2, var_TimeOpen, conn_TimeOpen);
      readData(3, var_TimeClose, conn_TimeClose);
      readData(4, var_Ts, conn_Ts);
      readData(5, var_Reset, conn_Reset);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbSimMotorGear::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Position, conn_Position);
      writeData(1, var_SensorOpen, conn_SensorOpen);
      writeData(2, var_SensorClose, conn_SensorClose);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbSimMotorGear::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_CmdOpen;
    case 1: return &var_CmdClose;
    case 2: return &var_TimeOpen;
    case 3: return &var_TimeClose;
    case 4: return &var_Ts;
    case 5: return &var_Reset;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbSimMotorGear::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Position;
    case 1: return &var_SensorOpen;
    case 2: return &var_SensorClose;
  }
  return nullptr;
}

CEventConnection *FORTE_FbSimMotorGear::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbSimMotorGear::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CmdOpen;
    case 1: return &conn_CmdClose;
    case 2: return &conn_TimeOpen;
    case 3: return &conn_TimeClose;
    case 4: return &conn_Ts;
    case 5: return &conn_Reset;
  }
  return nullptr;
}

CDataConnection *FORTE_FbSimMotorGear::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Position;
    case 1: return &conn_SensorOpen;
    case 2: return &conn_SensorClose;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbSimMotorGear::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_SpeedPos;
    case 1: return &var_SpeedNeg;
  }
  return nullptr;
}

void FORTE_FbSimMotorGear::alg_REQ(void) {

  #line 2 "FbSimMotorGear.fbt"
  if (var_Reset) {
    #line 3 "FbSimMotorGear.fbt"
    var_Position = 0.0_REAL;
  }
  #line 6 "FbSimMotorGear.fbt"
  var_SpeedPos = func_DIV<CIEC_REAL>(100.0_REAL, var_TimeOpen);
  #line 7 "FbSimMotorGear.fbt"
  var_SpeedNeg = func_DIV<CIEC_REAL>(100.0_REAL, var_TimeClose);
  #line 9 "FbSimMotorGear.fbt"
  if (var_CmdOpen) {
    #line 10 "FbSimMotorGear.fbt"
    var_Position = func_ADD<CIEC_REAL>(var_Position, func_MUL<CIEC_REAL>(var_SpeedPos, var_Ts));
  }
  #line 13 "FbSimMotorGear.fbt"
  if (var_CmdClose) {
    #line 14 "FbSimMotorGear.fbt"
    var_Position = func_SUB<CIEC_REAL>(var_Position, func_MUL<CIEC_REAL>(var_SpeedNeg, var_Ts));
  }
  #line 17 "FbSimMotorGear.fbt"
  if (func_GE(var_Position, 100.0_REAL)) {
    #line 18 "FbSimMotorGear.fbt"
    var_Position = 100.0_REAL;
    #line 19 "FbSimMotorGear.fbt"
    var_SensorOpen = true_BOOL;
  }
  else {
    #line 21 "FbSimMotorGear.fbt"
    var_SensorOpen = false_BOOL;
  }
  #line 24 "FbSimMotorGear.fbt"
  if (func_LE(var_Position, 0.0_REAL)) {
    #line 25 "FbSimMotorGear.fbt"
    var_Position = 0.0_REAL;
    #line 26 "FbSimMotorGear.fbt"
    var_SensorClose = true_BOOL;
  }
  else {
    #line 28 "FbSimMotorGear.fbt"
    var_SensorClose = false_BOOL;
  }
}
