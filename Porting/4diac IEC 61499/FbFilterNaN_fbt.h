/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbFilterNaN
 *** Description: Фильтр NaN и Inf для чисел REAL.
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

class FORTE_FbFilterNaN final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbFilterNaN)

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

    CIEC_BOOL var_Flag_nan_1;
    CIEC_BOOL var_Flag_nan_2;
    CIEC_BOOL var_Flag_nan_3;
    CIEC_BOOL var_Flag_pos_inf;
    CIEC_BOOL var_Flag_neg_inf;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbFilterNaN(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_In;
    CIEC_REAL var_ErrValue;

    CIEC_REAL var_Out;
    CIEC_BOOL var_Err;

    CIEC_REAL var_conn_Out;
    CIEC_BOOL var_conn_Err;

    CEventConnection conn_CNF;

    CDataConnection *conn_In;
    CDataConnection *conn_ErrValue;

    CDataConnection conn_Out;
    CDataConnection conn_Err;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paIn, const CIEC_REAL &paErrValue, CIEC_REAL &paOut, CIEC_BOOL &paErr) {
      var_In = paIn;
      var_ErrValue = paErrValue;
      executeEvent(scmEventREQID, nullptr);
      paOut = var_Out;
      paErr = var_Err;
    }

    void operator()(const CIEC_REAL &paIn, const CIEC_REAL &paErrValue, CIEC_REAL &paOut, CIEC_BOOL &paErr) {
      evt_REQ(paIn, paErrValue, paOut, paErr);
    }
};

