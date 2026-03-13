/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbPIDstep
 *** Description: ПИД-регулятор с двумя дискретными выходами.
 *** Version:
 ***     1.8: 2026-03-13/VA - LIB_PLC -
 *************************************************************************/

#include "FbPIDstep_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "FbPIDstep_fbt_gen.cpp"
#endif

#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_int.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_FbPIDstep, g_nStringIdFbPIDstep)

const CStringDictionary::TStringId FORTE_FbPIDstep::scmDataInputNames[] = {g_nStringIdPV, g_nStringIdSP, g_nStringIdCOM_RST, g_nStringIdLMNR_HS, g_nStringIdLMNR_LS, g_nStringIdLMNS_ON, g_nStringIdLMNUP, g_nStringIdLMNDN, g_nStringIdGAIN, g_nStringIdTI, g_nStringIdDEADB_W, g_nStringIdPULSE_TM, g_nStringIdBREAK_TM, g_nStringIdMTR_TM, g_nStringIdDISV, g_nStringIdCYCLE};
const CStringDictionary::TStringId FORTE_FbPIDstep::scmDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_FbPIDstep::scmDataOutputNames[] = {g_nStringIdQLMNUP, g_nStringIdQLMNDN};
const CStringDictionary::TStringId FORTE_FbPIDstep::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdBOOL};
const TDataIOID FORTE_FbPIDstep::scmEIWith[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, scmWithListDelimiter};
const TForteInt16 FORTE_FbPIDstep::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbPIDstep::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_FbPIDstep::scmEOWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_FbPIDstep::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_FbPIDstep::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_FbPIDstep::scmFBInterfaceSpec = {
  1, scmEventInputNames, nullptr, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, nullptr, scmEOWith, scmEOWithIndexes,
  16, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_FbPIDstep::scmInternalsNames[] = {g_nStringIdER, g_nStringIdLMNRS_ON, g_nStringIdLMNRSVAL, g_nStringIdLMNR_SIM, g_nStringIdsFbPVal, g_nStringIdsThrOn, g_nStringIdsiImpAus, g_nStringIdstImpDauer, g_nStringIdstPausDauer, g_nStringIdHvar, g_nStringIdErKp, g_nStringIdrTi, g_nStringIdAdapIn1, g_nStringIdAdapIn2, g_nStringIdiImpEin, g_nStringIdrThrOff, g_nStringIddInteg, g_nStringIddThrStIn, g_nStringIdLmnrSim};
const CStringDictionary::TStringId FORTE_FbPIDstep::scmInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdINT, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdINT, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};
const SInternalVarsInformation FORTE_FbPIDstep::scmInternalVars = {19, scmInternalsNames, scmInternalsTypeIds};

FORTE_FbPIDstep::FORTE_FbPIDstep(const CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer) :
    CSimpleFB(paContainer, scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_ER(0.0_REAL),
    var_LMNRS_ON(false_BOOL),
    var_LMNRSVAL(0.0_REAL),
    var_LMNR_SIM(0.0_REAL),
    var_sFbPVal(0.0_REAL),
    var_sThrOn(0.0_REAL),
    var_siImpAus(0_INT),
    var_stImpDauer(0.0_REAL),
    var_stPausDauer(0.0_REAL),
    var_Hvar(0.0_REAL),
    var_ErKp(0.0_REAL),
    var_rTi(0.0_REAL),
    var_AdapIn1(0.0_REAL),
    var_AdapIn2(0.0_REAL),
    var_iImpEin(0_INT),
    var_rThrOff(0.0_REAL),
    var_dInteg(0.0_REAL),
    var_dThrStIn(0.0_REAL),
    var_LmnrSim(0.0_REAL),
    var_PV(0.0_REAL),
    var_SP(0.0_REAL),
    var_COM_RST(false_BOOL),
    var_LMNR_HS(false_BOOL),
    var_LMNR_LS(false_BOOL),
    var_LMNS_ON(false_BOOL),
    var_LMNUP(false_BOOL),
    var_LMNDN(false_BOOL),
    var_GAIN(2.0_REAL),
    var_TI(20.0_REAL),
    var_DEADB_W(0.5_REAL),
    var_PULSE_TM(1.0_REAL),
    var_BREAK_TM(1.0_REAL),
    var_MTR_TM(55.0_REAL),
    var_DISV(0.0_REAL),
    var_CYCLE(0.1_REAL),
    var_QLMNUP(false_BOOL),
    var_QLMNDN(false_BOOL),
    var_conn_QLMNUP(var_QLMNUP),
    var_conn_QLMNDN(var_QLMNDN),
    conn_CNF(this, 0),
    conn_PV(nullptr),
    conn_SP(nullptr),
    conn_COM_RST(nullptr),
    conn_LMNR_HS(nullptr),
    conn_LMNR_LS(nullptr),
    conn_LMNS_ON(nullptr),
    conn_LMNUP(nullptr),
    conn_LMNDN(nullptr),
    conn_GAIN(nullptr),
    conn_TI(nullptr),
    conn_DEADB_W(nullptr),
    conn_PULSE_TM(nullptr),
    conn_BREAK_TM(nullptr),
    conn_MTR_TM(nullptr),
    conn_DISV(nullptr),
    conn_CYCLE(nullptr),
    conn_QLMNUP(this, 0, &var_conn_QLMNUP),
    conn_QLMNDN(this, 1, &var_conn_QLMNDN) {
}

void FORTE_FbPIDstep::setInitialValues() {
  var_ER = 0.0_REAL;
  var_LMNRS_ON = false_BOOL;
  var_LMNRSVAL = 0.0_REAL;
  var_LMNR_SIM = 0.0_REAL;
  var_sFbPVal = 0.0_REAL;
  var_sThrOn = 0.0_REAL;
  var_siImpAus = 0_INT;
  var_stImpDauer = 0.0_REAL;
  var_stPausDauer = 0.0_REAL;
  var_Hvar = 0.0_REAL;
  var_ErKp = 0.0_REAL;
  var_rTi = 0.0_REAL;
  var_AdapIn1 = 0.0_REAL;
  var_AdapIn2 = 0.0_REAL;
  var_iImpEin = 0_INT;
  var_rThrOff = 0.0_REAL;
  var_dInteg = 0.0_REAL;
  var_dThrStIn = 0.0_REAL;
  var_LmnrSim = 0.0_REAL;
  var_PV = 0.0_REAL;
  var_SP = 0.0_REAL;
  var_COM_RST = false_BOOL;
  var_LMNR_HS = false_BOOL;
  var_LMNR_LS = false_BOOL;
  var_LMNS_ON = false_BOOL;
  var_LMNUP = false_BOOL;
  var_LMNDN = false_BOOL;
  var_GAIN = 2.0_REAL;
  var_TI = 20.0_REAL;
  var_DEADB_W = 0.5_REAL;
  var_PULSE_TM = 1.0_REAL;
  var_BREAK_TM = 1.0_REAL;
  var_MTR_TM = 55.0_REAL;
  var_DISV = 0.0_REAL;
  var_CYCLE = 0.1_REAL;
  var_QLMNUP = false_BOOL;
  var_QLMNDN = false_BOOL;
}

void FORTE_FbPIDstep::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      enterStateREQ(paECET);
      break;
    default:
      break;
  }
}

void FORTE_FbPIDstep::enterStateREQ(CEventChainExecutionThread *const paECET) {
  alg_REQ();
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_FbPIDstep::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      readData(0, var_PV, conn_PV);
      readData(1, var_SP, conn_SP);
      readData(2, var_COM_RST, conn_COM_RST);
      readData(3, var_LMNR_HS, conn_LMNR_HS);
      readData(4, var_LMNR_LS, conn_LMNR_LS);
      readData(5, var_LMNS_ON, conn_LMNS_ON);
      readData(6, var_LMNUP, conn_LMNUP);
      readData(7, var_LMNDN, conn_LMNDN);
      readData(8, var_GAIN, conn_GAIN);
      readData(9, var_TI, conn_TI);
      readData(10, var_DEADB_W, conn_DEADB_W);
      readData(11, var_PULSE_TM, conn_PULSE_TM);
      readData(12, var_BREAK_TM, conn_BREAK_TM);
      readData(13, var_MTR_TM, conn_MTR_TM);
      readData(14, var_DISV, conn_DISV);
      readData(15, var_CYCLE, conn_CYCLE);
      break;
    }
    default:
      break;
  }
}

void FORTE_FbPIDstep::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      writeData(0, var_QLMNUP, conn_QLMNUP);
      writeData(1, var_QLMNDN, conn_QLMNDN);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_FbPIDstep::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_PV;
    case 1: return &var_SP;
    case 2: return &var_COM_RST;
    case 3: return &var_LMNR_HS;
    case 4: return &var_LMNR_LS;
    case 5: return &var_LMNS_ON;
    case 6: return &var_LMNUP;
    case 7: return &var_LMNDN;
    case 8: return &var_GAIN;
    case 9: return &var_TI;
    case 10: return &var_DEADB_W;
    case 11: return &var_PULSE_TM;
    case 12: return &var_BREAK_TM;
    case 13: return &var_MTR_TM;
    case 14: return &var_DISV;
    case 15: return &var_CYCLE;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbPIDstep::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QLMNUP;
    case 1: return &var_QLMNDN;
  }
  return nullptr;
}

CEventConnection *FORTE_FbPIDstep::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_FbPIDstep::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_PV;
    case 1: return &conn_SP;
    case 2: return &conn_COM_RST;
    case 3: return &conn_LMNR_HS;
    case 4: return &conn_LMNR_LS;
    case 5: return &conn_LMNS_ON;
    case 6: return &conn_LMNUP;
    case 7: return &conn_LMNDN;
    case 8: return &conn_GAIN;
    case 9: return &conn_TI;
    case 10: return &conn_DEADB_W;
    case 11: return &conn_PULSE_TM;
    case 12: return &conn_BREAK_TM;
    case 13: return &conn_MTR_TM;
    case 14: return &conn_DISV;
    case 15: return &conn_CYCLE;
  }
  return nullptr;
}

CDataConnection *FORTE_FbPIDstep::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QLMNUP;
    case 1: return &conn_QLMNDN;
  }
  return nullptr;
}

CIEC_ANY *FORTE_FbPIDstep::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_ER;
    case 1: return &var_LMNRS_ON;
    case 2: return &var_LMNRSVAL;
    case 3: return &var_LMNR_SIM;
    case 4: return &var_sFbPVal;
    case 5: return &var_sThrOn;
    case 6: return &var_siImpAus;
    case 7: return &var_stImpDauer;
    case 8: return &var_stPausDauer;
    case 9: return &var_Hvar;
    case 10: return &var_ErKp;
    case 11: return &var_rTi;
    case 12: return &var_AdapIn1;
    case 13: return &var_AdapIn2;
    case 14: return &var_iImpEin;
    case 15: return &var_rThrOff;
    case 16: return &var_dInteg;
    case 17: return &var_dThrStIn;
    case 18: return &var_LmnrSim;
  }
  return nullptr;
}

void FORTE_FbPIDstep::alg_REQ(void) {

  #line 2 "FbPIDstep.fbt"
  if (var_COM_RST) {
    #line 3 "FbPIDstep.fbt"
    var_LMNR_SIM = var_LMNRSVAL;
    #line 4 "FbPIDstep.fbt"
    var_QLMNUP = 0_BOOL;
    #line 5 "FbPIDstep.fbt"
    var_QLMNDN = 0_BOOL;
    #line 6 "FbPIDstep.fbt"
    var_ER = 0.0_REAL;
    #line 7 "FbPIDstep.fbt"
    var_LMNRS_ON = 0_BOOL;
    #line 8 "FbPIDstep.fbt"
    var_LMNRSVAL = 0.0_REAL;
    #line 9 "FbPIDstep.fbt"
    var_LMNR_SIM = 0.0_REAL;
    #line 10 "FbPIDstep.fbt"
    var_sFbPVal = 0.0_REAL;
    #line 11 "FbPIDstep.fbt"
    var_sThrOn = 0.0_REAL;
    #line 12 "FbPIDstep.fbt"
    var_siImpAus = 0_INT;
    #line 13 "FbPIDstep.fbt"
    var_stImpDauer = 0.0_REAL;
    #line 14 "FbPIDstep.fbt"
    var_stPausDauer = 0.0_REAL;
  }
  else {
    #line 16 "FbPIDstep.fbt"
    var_ErKp = func_SUB<CIEC_REAL>(var_SP, var_PV);
    #line 17 "FbPIDstep.fbt"
    if (func_LT(var_ErKp, func_MINUS<CIEC_REAL>(var_DEADB_W))) {
      #line 18 "FbPIDstep.fbt"
      var_ER = func_ADD<CIEC_REAL>(var_ErKp, var_DEADB_W);
    }
    else if (func_GT(var_ErKp, var_DEADB_W)) {
      #line 20 "FbPIDstep.fbt"
      var_ER = func_SUB<CIEC_REAL>(var_ErKp, var_DEADB_W);
    }
    else {
      #line 22 "FbPIDstep.fbt"
      var_ER = 0.0_REAL;
    }
    #line 24 "FbPIDstep.fbt"
    var_ErKp = func_MUL<CIEC_REAL>(var_ER, var_GAIN);
    #line 25 "FbPIDstep.fbt"
    var_rTi = var_TI;
    #line 26 "FbPIDstep.fbt"
    if (func_LT(var_rTi, func_MUL<CIEC_REAL>(var_CYCLE, 0.5_REAL))) {
      #line 27 "FbPIDstep.fbt"
      var_rTi = func_MUL<CIEC_REAL>(var_CYCLE, 0.5_REAL);
    }
    #line 29 "FbPIDstep.fbt"
    var_Hvar = func_SUB<CIEC_REAL>(var_rTi, func_ABS(func_MUL<CIEC_REAL>(func_MUL<CIEC_REAL>(0.01_REAL, var_ErKp), var_MTR_TM)));
    #line 30 "FbPIDstep.fbt"
    if (func_LT(var_Hvar, func_MUL<CIEC_REAL>(var_rTi, 0.1_REAL))) {
      #line 31 "FbPIDstep.fbt"
      var_rTi = func_MUL<CIEC_REAL>(var_rTi, 0.1_REAL);
    }
    else {
      #line 33 "FbPIDstep.fbt"
      var_rTi = var_Hvar;
    }
    #line 35 "FbPIDstep.fbt"
    if (var_LMNS_ON) {
      #line 36 "FbPIDstep.fbt"
      var_sFbPVal = 0.0_REAL;
    }
    else {
      #line 38 "FbPIDstep.fbt"
      if (func_NE(var_siImpAus, 0_INT)) {
        #line 39 "FbPIDstep.fbt"
        var_dInteg = func_DIV<CIEC_REAL>(func_MUL<CIEC_REAL>(func_INT_TO_REAL(var_siImpAus), var_CYCLE), var_MTR_TM);
      }
      else {
        #line 41 "FbPIDstep.fbt"
        if (func_OR<CIEC_BOOL>(func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_GT(var_ErKp, 0.0_REAL), var_LMNR_HS), func_AND<CIEC_BOOL>(func_LT(var_ErKp, 0.0_REAL), var_LMNR_LS)), func_EQ(var_TI, 0.0_REAL))) {
          #line 42 "FbPIDstep.fbt"
          var_dInteg = 0.0_REAL;
        }
        else {
          #line 44 "FbPIDstep.fbt"
          var_dInteg = func_DIV<CIEC_REAL>(func_MUL<CIEC_REAL>(func_MINUS<CIEC_REAL>(var_ErKp), var_CYCLE), var_rTi);
        }
      }
      #line 47 "FbPIDstep.fbt"
      var_sFbPVal = func_ADD<CIEC_REAL>(var_sFbPVal, var_dInteg);
      #line 48 "FbPIDstep.fbt"
      if (func_EQ(var_TI, 0.0_REAL)) {
        #line 49 "FbPIDstep.fbt"
        if (func_GT(var_sFbPVal, 100.0_REAL)) {
          #line 50 "FbPIDstep.fbt"
          var_sFbPVal = 100.0_REAL;
        }
        else if (func_LT(var_sFbPVal, 0.0_REAL)) {
          #line 52 "FbPIDstep.fbt"
          var_sFbPVal = 0.0_REAL;
        }
      }
    }
    #line 56 "FbPIDstep.fbt"
    var_dThrStIn = func_ADD<CIEC_REAL>(func_SUB<CIEC_REAL>(var_ErKp, var_sFbPVal), var_DISV);
    #line 57 "FbPIDstep.fbt"
    var_AdapIn1 = var_ErKp;
    #line 58 "FbPIDstep.fbt"
    var_AdapIn2 = var_sFbPVal;
    #line 59 "FbPIDstep.fbt"
    var_rThrOff = func_MUL<CIEC_REAL>(func_DIV<CIEC_REAL>(55.0_REAL, var_MTR_TM), var_CYCLE);
    #line 60 "FbPIDstep.fbt"
    if (func_GT(var_PULSE_TM, var_CYCLE)) {
      #line 61 "FbPIDstep.fbt"
      var_Hvar = var_PULSE_TM;
    }
    else {
      #line 63 "FbPIDstep.fbt"
      var_Hvar = var_CYCLE;
    }
    #line 65 "FbPIDstep.fbt"
    var_Hvar = func_DIV<CIEC_REAL>(func_MUL<CIEC_REAL>(100.0_REAL, var_Hvar), var_MTR_TM);
    #line 66 "FbPIDstep.fbt"
    if (func_NOT<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_LMNR_HS, var_LMNR_LS))) {
      #line 67 "FbPIDstep.fbt"
      if (func_NOT<CIEC_BOOL>(func_OR<CIEC_BOOL>(var_QLMNUP, var_QLMNDN))) {
        #line 68 "FbPIDstep.fbt"
        if (func_NE(var_TI, 0.0_REAL)) {
          #line 69 "FbPIDstep.fbt"
          if (func_LT(func_ABS(var_AdapIn1), func_ABS(var_AdapIn2))) {
            #line 70 "FbPIDstep.fbt"
            var_sThrOn = var_AdapIn1;
          }
          else {
            #line 72 "FbPIDstep.fbt"
            var_sThrOn = var_AdapIn2;
          }
        }
        else {
          #line 75 "FbPIDstep.fbt"
          if (func_EQ(var_PV, 0.0_REAL)) {
            #line 76 "FbPIDstep.fbt"
            var_sThrOn = var_Hvar;
          }
          else {
            #line 78 "FbPIDstep.fbt"
            var_sThrOn = func_MUL<CIEC_REAL>(func_ABS(var_ErKp), 0.5_REAL);
          }
        }
        #line 81 "FbPIDstep.fbt"
        if (func_GT(var_sThrOn, 10.0_REAL)) {
          #line 82 "FbPIDstep.fbt"
          var_sThrOn = 10.0_REAL;
        }
        #line 84 "FbPIDstep.fbt"
        if (func_LT(var_sThrOn, var_Hvar)) {
          #line 85 "FbPIDstep.fbt"
          var_sThrOn = var_Hvar;
        }
      }
    }
    else {
      #line 89 "FbPIDstep.fbt"
      var_sThrOn = var_Hvar;
    }
    #line 91 "FbPIDstep.fbt"
    if (func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(var_siImpAus, 100_INT), func_GT(var_dThrStIn, var_rThrOff)), func_GE(var_dThrStIn, var_sThrOn))) {
      #line 92 "FbPIDstep.fbt"
      var_iImpEin = 100_INT;
    }
    else if (func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(var_siImpAus, -100_INT), func_LT(var_dThrStIn, func_MINUS<CIEC_REAL>(var_rThrOff))), func_LE(var_dThrStIn, func_MINUS<CIEC_REAL>(var_sThrOn)))) {
      #line 94 "FbPIDstep.fbt"
      var_iImpEin = -100_INT;
    }
    else {
      #line 96 "FbPIDstep.fbt"
      var_iImpEin = 0_INT;
    }
    #line 98 "FbPIDstep.fbt"
    if (var_LMNS_ON) {
      #line 99 "FbPIDstep.fbt"
      if (func_XOR<CIEC_BOOL>(var_LMNUP, var_LMNDN)) {
        #line 100 "FbPIDstep.fbt"
        if (var_LMNUP) {
          #line 101 "FbPIDstep.fbt"
          var_iImpEin = 100_INT;
        }
        else {
          #line 103 "FbPIDstep.fbt"
          var_iImpEin = -100_INT;
        }
      }
      else {
        #line 106 "FbPIDstep.fbt"
        var_iImpEin = 0_INT;
      }
    }
    #line 109 "FbPIDstep.fbt"
    if (func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(var_iImpEin, 100_INT), var_LMNR_HS), func_AND<CIEC_BOOL>(func_EQ(var_iImpEin, -100_INT), var_LMNR_LS))) {
      #line 110 "FbPIDstep.fbt"
      var_iImpEin = 0_INT;
    }
    #line 112 "FbPIDstep.fbt"
    if (func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(var_siImpAus, -100_INT), func_EQ(var_iImpEin, 100_INT)), func_AND<CIEC_BOOL>(func_EQ(var_siImpAus, 100_INT), func_EQ(var_iImpEin, -100_INT)))) {
      #line 113 "FbPIDstep.fbt"
      var_iImpEin = 0_INT;
    }
    #line 115 "FbPIDstep.fbt"
    if (func_NE(var_siImpAus, var_iImpEin)) {
      #line 116 "FbPIDstep.fbt"
      if (func_EQ(var_iImpEin, 0_INT)) {
        #line 117 "FbPIDstep.fbt"
        if (func_LE(var_stImpDauer, 0.0_REAL)) {
          #line 118 "FbPIDstep.fbt"
          var_siImpAus = 0_INT;
          #line 119 "FbPIDstep.fbt"
          var_stPausDauer = var_BREAK_TM;
        }
      }
      else {
        #line 122 "FbPIDstep.fbt"
        var_siImpAus = var_iImpEin;
        #line 123 "FbPIDstep.fbt"
        var_stImpDauer = var_PULSE_TM;
      }
    }
    #line 126 "FbPIDstep.fbt"
    if (func_GT(var_stImpDauer, 0.0_REAL)) {
      #line 127 "FbPIDstep.fbt"
      var_stImpDauer = func_SUB<CIEC_REAL>(var_stImpDauer, var_CYCLE);
    }
    else {
      #line 129 "FbPIDstep.fbt"
      var_stImpDauer = 0.0_REAL;
    }
    #line 131 "FbPIDstep.fbt"
    if (func_GT(var_stPausDauer, 0.0_REAL)) {
      #line 132 "FbPIDstep.fbt"
      var_stPausDauer = func_SUB<CIEC_REAL>(var_stPausDauer, var_CYCLE);
    }
    else {
      #line 134 "FbPIDstep.fbt"
      var_stPausDauer = 0.0_REAL;
    }
    #line 136 "FbPIDstep.fbt"
    if (func_OR<CIEC_BOOL>(func_AND<CIEC_BOOL>(func_EQ(var_siImpAus, 100_INT), var_LMNR_HS), func_AND<CIEC_BOOL>(func_EQ(var_siImpAus, -100_INT), var_LMNR_LS))) {
      #line 137 "FbPIDstep.fbt"
      var_siImpAus = 0_INT;
      #line 138 "FbPIDstep.fbt"
      var_stImpDauer = 0.0_REAL;
    }
    #line 140 "FbPIDstep.fbt"
    if (func_NOT<CIEC_BOOL>(var_LMNRS_ON)) {
      #line 141 "FbPIDstep.fbt"
      var_LmnrSim = var_LMNRSVAL;
    }
    else {
      #line 143 "FbPIDstep.fbt"
      var_LmnrSim = func_ADD<CIEC_REAL>(func_DIV<CIEC_REAL>(func_MUL<CIEC_REAL>(func_INT_TO_REAL(var_siImpAus), var_CYCLE), var_MTR_TM), var_LMNR_SIM);
      #line 144 "FbPIDstep.fbt"
      if (func_GE(var_LmnrSim, 100.0_REAL)) {
        #line 145 "FbPIDstep.fbt"
        var_LmnrSim = 100.0_REAL;
      }
      else if (func_LE(var_LmnrSim, 0.0_REAL)) {
        #line 147 "FbPIDstep.fbt"
        var_LmnrSim = 0.0_REAL;
      }
    }
    #line 150 "FbPIDstep.fbt"
    var_LMNR_SIM = var_LmnrSim;
    #line 151 "FbPIDstep.fbt"
    if (func_EQ(var_siImpAus, 0_INT)) {
      #line 152 "FbPIDstep.fbt"
      var_QLMNUP = 0_BOOL;
      #line 153 "FbPIDstep.fbt"
      var_QLMNDN = 0_BOOL;
    }
    else if (func_EQ(var_siImpAus, 100_INT)) {
      #line 155 "FbPIDstep.fbt"
      var_QLMNUP = 1_BOOL;
      #line 156 "FbPIDstep.fbt"
      var_QLMNDN = 0_BOOL;
    }
    else {
      #line 158 "FbPIDstep.fbt"
      var_QLMNUP = 0_BOOL;
      #line 159 "FbPIDstep.fbt"
      var_QLMNDN = 1_BOOL;
    }
  }
}
