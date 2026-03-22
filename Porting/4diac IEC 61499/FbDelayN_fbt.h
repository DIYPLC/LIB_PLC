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

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_int.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbDelayN final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbDelayN)

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

    CIEC_ARRAY_FIXED<CIEC_REAL, 0, 98> var_Buffer1;

    static const CIEC_INT var_const_NUMBER;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbDelayN(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_In;

    CIEC_REAL var_Out;

    CIEC_REAL var_conn_Out;

    CEventConnection conn_CNF;

    CDataConnection *conn_In;

    CDataConnection conn_Out;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paIn, CIEC_REAL &paOut) {
      var_In = paIn;
      executeEvent(scmEventREQID, nullptr);
      paOut = var_Out;
    }

    void operator()(const CIEC_REAL &paIn, CIEC_REAL &paOut) {
      evt_REQ(paIn, paOut);
    }
};

