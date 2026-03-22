/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbPIDcontrol
 *** Description: ПИД-регулятор.
 *** Version:
 ***     3.6: 2026-03-06/VA - LIB_PLC -
 *************************************************************************/

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbPIDcontrol final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbPIDcontrol)

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
    CIEC_REAL var_Ppart;
    CIEC_REAL var_Ipart;
    CIEC_REAL var_Dpart;
    CIEC_REAL var_Dintegral;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbPIDcontrol(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_PV;
    CIEC_REAL var_SP;
    CIEC_REAL var_Kp;
    CIEC_REAL var_Ki;
    CIEC_REAL var_Kd;
    CIEC_REAL var_Kdf;
    CIEC_REAL var_ERMAX;
    CIEC_REAL var_ERMIN;
    CIEC_REAL var_MVMAX;
    CIEC_REAL var_MVMIN;
    CIEC_REAL var_Ts;
    CIEC_REAL var_Manual;
    CIEC_BOOL var_OnMan;

    CIEC_REAL var_MV;

    CIEC_REAL var_conn_MV;

    CEventConnection conn_CNF;

    CDataConnection *conn_PV;
    CDataConnection *conn_SP;
    CDataConnection *conn_Kp;
    CDataConnection *conn_Ki;
    CDataConnection *conn_Kd;
    CDataConnection *conn_Kdf;
    CDataConnection *conn_ERMAX;
    CDataConnection *conn_ERMIN;
    CDataConnection *conn_MVMAX;
    CDataConnection *conn_MVMIN;
    CDataConnection *conn_Ts;
    CDataConnection *conn_Manual;
    CDataConnection *conn_OnMan;

    CDataConnection conn_MV;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paPV, const CIEC_REAL &paSP, const CIEC_REAL &paKp, const CIEC_REAL &paKi, const CIEC_REAL &paKd, const CIEC_REAL &paKdf, const CIEC_REAL &paERMAX, const CIEC_REAL &paERMIN, const CIEC_REAL &paMVMAX, const CIEC_REAL &paMVMIN, const CIEC_REAL &paTs, const CIEC_REAL &paManual, const CIEC_BOOL &paOnMan, CIEC_REAL &paMV) {
      var_PV = paPV;
      var_SP = paSP;
      var_Kp = paKp;
      var_Ki = paKi;
      var_Kd = paKd;
      var_Kdf = paKdf;
      var_ERMAX = paERMAX;
      var_ERMIN = paERMIN;
      var_MVMAX = paMVMAX;
      var_MVMIN = paMVMIN;
      var_Ts = paTs;
      var_Manual = paManual;
      var_OnMan = paOnMan;
      executeEvent(scmEventREQID, nullptr);
      paMV = var_MV;
    }

    void operator()(const CIEC_REAL &paPV, const CIEC_REAL &paSP, const CIEC_REAL &paKp, const CIEC_REAL &paKi, const CIEC_REAL &paKd, const CIEC_REAL &paKdf, const CIEC_REAL &paERMAX, const CIEC_REAL &paERMIN, const CIEC_REAL &paMVMAX, const CIEC_REAL &paMVMIN, const CIEC_REAL &paTs, const CIEC_REAL &paManual, const CIEC_BOOL &paOnMan, CIEC_REAL &paMV) {
      evt_REQ(paPV, paSP, paKp, paKi, paKd, paKdf, paERMAX, paERMIN, paMVMAX, paMVMIN, paTs, paManual, paOnMan, paMV);
    }
};

