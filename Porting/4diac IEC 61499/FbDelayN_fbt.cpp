/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbDelayN
 *** Description: Блок задержки сигнала на 100 тактов.
 *** Version:
 ***     2.3: 2026-03-22/VA - LIB_PLC -
 *************************************************************************/

#include "FbDelayN_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbDelayN_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_int.h"
#include "core/datatypes/forte_real.h"
#include "core/datatypes/forte_sint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbDelayN, g_nStringIdFbDelayN)

const CStringDictionary::TStringId FORTE_FbDelayN::scmDataInputNames[] = {g_nStringIdIn};
const CStringDictionary::TStringId FORTE_FbDelayN::scmDataInputTypeIds[] = {g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbDelayN::scmDataOutputNames[] = {g_nStringIdOut};
const CStringDictionary::TStringId FORTE_FbDelayN::scmDataOutputTypeIds[] = {g_nStringIdREAL};
const TDataIOID FORTE_FbDelayN::scmEIWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbDelayN::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbDelayN::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbDelayN::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_FbDelayN::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbDelayN::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbDelayN::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  1, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbDelayN::scmInternalsNames[] = {g_nStringIdBuffer1};
const CStringDictionary::TStringId FORTE_FbDelayN::scmInternalsTypeIds[] = {g_nStringIdARRAY, static_cast<CStringDictionary::TStringId>(0), static_cast<CStringDictionary::TStringId>(98), g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbDelayN::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

const CIEC_INT FORTE_FbDelayN::var_const_NUMBER = 98_INT;


FORTE_FbDelayN::FORTE_FbDelayN(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_Buffer1(CIEC_ARRAY_FIXED<CIEC_REAL, 0, 98>{}),
    var_In(0.0_REAL),
    var_Out(0.0_REAL),
    var_conn_Out(var_Out),
    conn_CNF(this, 0),
    conn_In(nullptr),
    conn_Out(this, 0, &var_conn_Out) {
}

void FORTE_FbDelayN::setInitialValues() {
  var_Buffer1 = CIEC_ARRAY_FIXED<CIEC_REAL, 0, 98>{};
  var_In = 0.0_REAL;
  var_Out = 0.0_REAL;
}

void FORTE_FbDelayN::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbDelayN::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbDelayN::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_In, conn_In);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbDelayN::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_Out, conn_Out);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbDelayN::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_In;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbDelayN::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Out;
  }
  return nullptr;
}

CEventConnection *FORTE_FbDelayN::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbDelayN::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_In;
  }
  return nullptr;
}

CDataConnection *FORTE_FbDelayN::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Out;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbDelayN::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Buffer1;
  }
  return nullptr;
}

void FORTE_FbDelayN::alg_REQ(void) {
  CIEC_INT st_lv_Counter1 = 0_INT;

  #line 8 "FbDelayN.fbt"
  var_Out = var_Buffer1[var_const_NUMBER];
  #line 9 "FbDelayN.fbt"
  for (auto st_lv_synthetic_0 : ST_FOR_ITER<CIEC_INT, CIEC_INT>(st_lv_Counter1, var_const_NUMBER, 1_INT, -1_INT)) {
    #line 10 "FbDelayN.fbt"
    var_Buffer1[st_lv_Counter1] = var_Buffer1[func_SUB<CIEC_INT>(st_lv_Counter1, 1_INT)];
  }
  #line 12 "FbDelayN.fbt"
  var_Buffer1[0_SINT] = var_In;
}
