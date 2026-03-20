/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: Fb2PosControl
 *** Description: Регулятор двухпозиционный.
 *** Version:
 ***     2.1: 2026-03-20/VA - LIB_PLC -
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

class FORTE_Fb2PosControl final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_Fb2PosControl)

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
    FORTE_Fb2PosControl(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_PV;
    CIEC_REAL var_SP;
    CIEC_REAL var_HYST;

    CIEC_BOOL var_OP;

    CIEC_BOOL var_conn_OP;

    CEventConnection conn_CNF;

    CDataConnection *conn_PV;
    CDataConnection *conn_SP;
    CDataConnection *conn_HYST;

    CDataConnection conn_OP;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paPV, const CIEC_REAL &paSP, const CIEC_REAL &paHYST, CIEC_BOOL &paOP) {
      var_PV = paPV;
      var_SP = paSP;
      var_HYST = paHYST;
      executeEvent(scmEventREQID, nullptr);
      paOP = var_OP;
    }

    void operator()(const CIEC_REAL &paPV, const CIEC_REAL &paSP, const CIEC_REAL &paHYST, CIEC_BOOL &paOP) {
      evt_REQ(paPV, paSP, paHYST, paOP);
    }
};

