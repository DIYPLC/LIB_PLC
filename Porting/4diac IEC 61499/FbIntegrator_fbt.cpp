/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbIntegrator
 *** Description: Интегратор W(s)=1/s.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#include "FbIntegrator_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbIntegrator_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbIntegrator, g_nStringIdFbIntegrator)

const CStringDictionary::TStringId FORTE_FbIntegrator::scmDataInputNames[] = {g_nStringIdIn, g_nStringIdOutMax, g_nStringIdOutMin, g_nStringIdInitValue, g_nStringIdTrapezoid, g_nStringIdTs, g_nStringIdReset};
const CStringDictionary::TStringId FORTE_FbIntegrator::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_FbIntegrator::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbIntegrator::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbIntegrator::scmEIWith[] = {0, 1, 2, 3, 4, 5, 6, scmWithListDelimiter};
const TForteInt16 FORTE_FbIntegrator::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbIntegrator::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbIntegrator::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbIntegrator::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbIntegrator::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbIntegrator::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  7, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbIntegrator::scmInternalsNames[] = {g_nStringIdInPrevious};
const CStringDictionary::TStringId FORTE_FbIntegrator::scmInternalsTypeIds[] = {g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbIntegrator::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbIntegrator::FORTE_FbIntegrator(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_InPrevious(0.0_REAL),
    var_In(0.0_REAL),
    var_OutMax(1000000.0_REAL),
    var_OutMin(-1000000.0_REAL),
    var_InitValue(0.0_REAL),
    var_Trapezoid(false_BOOL),
    var_Ts(0.1_REAL),
    var_Reset(false_BOOL),
    var_Out(0.0_REAL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_OutMax(nullptr),
    conn_OutMin(nullptr),
    conn_InitValue(nullptr),
    conn_Trapezoid(nullptr),
    conn_Ts(nullptr),
    conn_Reset(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbIntegrator::setInitialValues() {
  var_InPrevious = 0.0_REAL;
  var_In = 0.0_REAL;
  var_OutMax = 1000000.0_REAL;
  var_OutMin = -1000000.0_REAL;
  var_InitValue = 0.0_REAL;
  var_Trapezoid = false_BOOL;
  var_Ts = 0.1_REAL;
  var_Reset = false_BOOL;
  var_Out = 0.0_REAL;
}

void FORTE_FbIntegrator::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbIntegrator::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbIntegrator::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      readData(1, var_OutMax, conn_OutMax);
      readData(2, var_OutMin, conn_OutMin);
      readData(3, var_InitValue, conn_InitValue);
      readData(4, var_Trapezoid, conn_Trapezoid);
      readData(5, var_Ts, conn_Ts);
      readData(6, var_Reset, conn_Reset);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbIntegrator::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbIntegrator::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
    case 1: return &var_OutMax;
    case 2: return &var_OutMin;
    case 3: return &var_InitValue;
    case 4: return &var_Trapezoid;
    case 5: return &var_Ts;
    case 6: return &var_Reset;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbIntegrator::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbIntegrator::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbIntegrator::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
    case 1: return &conn_OutMax;
    case 2: return &conn_OutMin;
    case 3: return &conn_InitValue;
    case 4: return &conn_Trapezoid;
    case 5: return &conn_Ts;
    case 6: return &conn_Reset;
  }
  return nullptr;
}

CDataConnection *FORTE_FbIntegrator::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbIntegrator::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_InPrevious;
  }
  return nullptr;
}

void FORTE_FbIntegrator::alg_REQ(void) {

  #line 2 "FbIntegrator.fbt"
  if (var_Trapezoid) {
    #line 6 "FbIntegrator.fbt"
    var_Out = func_ADD<CIEC_REAL>(var_Out, func_MUL<CIEC_REAL>(func_MUL<CIEC_REAL>(func_ADD<CIEC_REAL>(var_In, var_InPrevious), 0.5_REAL), var_Ts));
  }
  else {
    #line 10 "FbIntegrator.fbt"
    var_Out = func_ADD<CIEC_REAL>(var_Out, func_MUL<CIEC_REAL>(var_In, var_Ts));
  }
  #line 13 "FbIntegrator.fbt"
  var_InPrevious = var_In;
  #line 15 "FbIntegrator.fbt"
  if (var_Reset) {
    #line 16 "FbIntegrator.fbt"
    var_Out = var_InitValue;
  }
  #line 19 "FbIntegrator.fbt"
  if (func_GE(var_Out, var_OutMax)) {
    #line 20 "FbIntegrator.fbt"
    var_Out = var_OutMax;
  }
  #line 23 "FbIntegrator.fbt"
  if (func_LE(var_Out, var_OutMin)) {
    #line 24 "FbIntegrator.fbt"
    var_Out = var_OutMin;
  }
}
