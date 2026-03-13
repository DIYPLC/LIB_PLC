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

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_int.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbPIDstep final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbPIDstep)

  private:
    static const CStringDictionary::TStringId scmDataInputNames[];
    static const CStringDictionary::TStringId scmDataInputTypeIds[];
    static const CStringDictionary::TStringId scmDataOutputNames[];
    static const CStringDictionary::TStringId scmDataOutputTypeIds[];
    static const TEventID scmEventREQID = 0;
    static const TDataIOID scmEIWith[];
    static const TForteInt16 scmEIWithIndexes[];
    static const CStringDictionary::TStringId scmEventInputNames[];
    static const TEventID scmEventCNFID = 0;
    static const TDataIOID scmEOWith[];
    static const TForteInt16 scmEOWithIndexes[];
    static const CStringDictionary::TStringId scmEventOutputNames[];

    static const SFBInterfaceSpec scmFBInterfaceSpec;

    static const CStringDictionary::TStringId scmInternalsNames[];
    static const CStringDictionary::TStringId scmInternalsTypeIds[];
    static const SInternalVarsInformation scmInternalVars;

    CIEC_REAL var_ER;
    CIEC_BOOL var_LMNRS_ON;
    CIEC_REAL var_LMNRSVAL;
    CIEC_REAL var_LMNR_SIM;
    CIEC_REAL var_sFbPVal;
    CIEC_REAL var_sThrOn;
    CIEC_INT var_siImpAus;
    CIEC_REAL var_stImpDauer;
    CIEC_REAL var_stPausDauer;
    CIEC_REAL var_Hvar;
    CIEC_REAL var_ErKp;
    CIEC_REAL var_rTi;
    CIEC_REAL var_AdapIn1;
    CIEC_REAL var_AdapIn2;
    CIEC_INT var_iImpEin;
    CIEC_REAL var_rThrOff;
    CIEC_REAL var_dInteg;
    CIEC_REAL var_dThrStIn;
    CIEC_REAL var_LmnrSim;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbPIDstep(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_PV;
    CIEC_REAL var_SP;
    CIEC_BOOL var_COM_RST;
    CIEC_BOOL var_LMNR_HS;
    CIEC_BOOL var_LMNR_LS;
    CIEC_BOOL var_LMNS_ON;
    CIEC_BOOL var_LMNUP;
    CIEC_BOOL var_LMNDN;
    CIEC_REAL var_GAIN;
    CIEC_REAL var_TI;
    CIEC_REAL var_DEADB_W;
    CIEC_REAL var_PULSE_TM;
    CIEC_REAL var_BREAK_TM;
    CIEC_REAL var_MTR_TM;
    CIEC_REAL var_DISV;
    CIEC_REAL var_CYCLE;

    CIEC_BOOL var_QLMNUP;
    CIEC_BOOL var_QLMNDN;

    CIEC_BOOL var_conn_QLMNUP;
    CIEC_BOOL var_conn_QLMNDN;

    CEventConnection conn_CNF;

    CDataConnection *conn_PV;
    CDataConnection *conn_SP;
    CDataConnection *conn_COM_RST;
    CDataConnection *conn_LMNR_HS;
    CDataConnection *conn_LMNR_LS;
    CDataConnection *conn_LMNS_ON;
    CDataConnection *conn_LMNUP;
    CDataConnection *conn_LMNDN;
    CDataConnection *conn_GAIN;
    CDataConnection *conn_TI;
    CDataConnection *conn_DEADB_W;
    CDataConnection *conn_PULSE_TM;
    CDataConnection *conn_BREAK_TM;
    CDataConnection *conn_MTR_TM;
    CDataConnection *conn_DISV;
    CDataConnection *conn_CYCLE;

    CDataConnection conn_QLMNUP;
    CDataConnection conn_QLMNDN;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paPV, const CIEC_REAL &paSP, const CIEC_BOOL &paCOM_RST, const CIEC_BOOL &paLMNR_HS, const CIEC_BOOL &paLMNR_LS, const CIEC_BOOL &paLMNS_ON, const CIEC_BOOL &paLMNUP, const CIEC_BOOL &paLMNDN, const CIEC_REAL &paGAIN, const CIEC_REAL &paTI, const CIEC_REAL &paDEADB_W, const CIEC_REAL &paPULSE_TM, const CIEC_REAL &paBREAK_TM, const CIEC_REAL &paMTR_TM, const CIEC_REAL &paDISV, const CIEC_REAL &paCYCLE, CIEC_BOOL &paQLMNUP, CIEC_BOOL &paQLMNDN) {
      var_PV = paPV;
      var_SP = paSP;
      var_COM_RST = paCOM_RST;
      var_LMNR_HS = paLMNR_HS;
      var_LMNR_LS = paLMNR_LS;
      var_LMNS_ON = paLMNS_ON;
      var_LMNUP = paLMNUP;
      var_LMNDN = paLMNDN;
      var_GAIN = paGAIN;
      var_TI = paTI;
      var_DEADB_W = paDEADB_W;
      var_PULSE_TM = paPULSE_TM;
      var_BREAK_TM = paBREAK_TM;
      var_MTR_TM = paMTR_TM;
      var_DISV = paDISV;
      var_CYCLE = paCYCLE;
      executeEvent(scmEventREQID, nullptr);
      paQLMNUP = var_QLMNUP;
      paQLMNDN = var_QLMNDN;
    }

    void operator()(const CIEC_REAL &paPV, const CIEC_REAL &paSP, const CIEC_BOOL &paCOM_RST, const CIEC_BOOL &paLMNR_HS, const CIEC_BOOL &paLMNR_LS, const CIEC_BOOL &paLMNS_ON, const CIEC_BOOL &paLMNUP, const CIEC_BOOL &paLMNDN, const CIEC_REAL &paGAIN, const CIEC_REAL &paTI, const CIEC_REAL &paDEADB_W, const CIEC_REAL &paPULSE_TM, const CIEC_REAL &paBREAK_TM, const CIEC_REAL &paMTR_TM, const CIEC_REAL &paDISV, const CIEC_REAL &paCYCLE, CIEC_BOOL &paQLMNUP, CIEC_BOOL &paQLMNDN) {
      evt_REQ(paPV, paSP, paCOM_RST, paLMNR_HS, paLMNR_LS, paLMNS_ON, paLMNUP, paLMNDN, paGAIN, paTI, paDEADB_W, paPULSE_TM, paBREAK_TM, paMTR_TM, paDISV, paCYCLE, paQLMNUP, paQLMNDN);
    }
};

