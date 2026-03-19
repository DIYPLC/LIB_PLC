/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbFilterA
 *** Description: Фильтр апериодический.
 *** Version:
 ***     2.1: 2026-03-19/VA - LIB_PLC -
 *************************************************************************/

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbFilterA final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbFilterA)

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

    CIEC_REAL var_Tmp;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbFilterA(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_In;
    CIEC_REAL var_Tf;
    CIEC_REAL var_Ts;

    CIEC_REAL var_Out;

    CIEC_REAL var_conn_Out;

    CEventConnection conn_CNF;

    CDataConnection *conn_In;
    CDataConnection *conn_Tf;
    CDataConnection *conn_Ts;

    CDataConnection conn_Out;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paIn, const CIEC_REAL &paTf, const CIEC_REAL &paTs, CIEC_REAL &paOut) {
      var_In = paIn;
      var_Tf = paTf;
      var_Ts = paTs;
      executeEvent(scmEventREQID, nullptr);
      paOut = var_Out;
    }

    void operator()(const CIEC_REAL &paIn, const CIEC_REAL &paTf, const CIEC_REAL &paTs, CIEC_REAL &paOut) {
      evt_REQ(paIn, paTf, paTs, paOut);
    }
};

