/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Fb3PosControl
 *** Description: Регулятор трехпозиционный.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
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

class FORTE_Fb3PosControl final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_Fb3PosControl)

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

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_Fb3PosControl(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_PV;
    CIEC_REAL var_SP;
    CIEC_REAL var_DBand;
    CIEC_REAL var_HystPos;
    CIEC_REAL var_HystNeg;

    CIEC_BOOL var_OpPos;
    CIEC_BOOL var_OpNeg;

    CIEC_BOOL var_conn_OpPos;
    CIEC_BOOL var_conn_OpNeg;

    CEventConnection conn_CNF;

    CDataConnection *conn_PV;
    CDataConnection *conn_SP;
    CDataConnection *conn_DBand;
    CDataConnection *conn_HystPos;
    CDataConnection *conn_HystNeg;

    CDataConnection conn_OpPos;
    CDataConnection conn_OpNeg;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paPV, const CIEC_REAL &paSP, const CIEC_REAL &paDBand, const CIEC_REAL &paHystPos, const CIEC_REAL &paHystNeg, CIEC_BOOL &paOpPos, CIEC_BOOL &paOpNeg) {
      var_PV = paPV;
      var_SP = paSP;
      var_DBand = paDBand;
      var_HystPos = paHystPos;
      var_HystNeg = paHystNeg;
      executeEvent(scmEventREQID, nullptr);
      paOpPos = var_OpPos;
      paOpNeg = var_OpNeg;
    }

    void operator()(const CIEC_REAL &paPV, const CIEC_REAL &paSP, const CIEC_REAL &paDBand, const CIEC_REAL &paHystPos, const CIEC_REAL &paHystNeg, CIEC_BOOL &paOpPos, CIEC_BOOL &paOpNeg) {
      evt_REQ(paPV, paSP, paDBand, paHystPos, paHystNeg, paOpPos, paOpNeg);
    }
};

