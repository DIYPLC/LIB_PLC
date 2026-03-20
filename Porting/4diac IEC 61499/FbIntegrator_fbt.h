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

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_real.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbIntegrator final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbIntegrator)

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

    CIEC_REAL var_InPrevious;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbIntegrator(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_In;
    CIEC_REAL var_OutMax;
    CIEC_REAL var_OutMin;
    CIEC_REAL var_InitValue;
    CIEC_BOOL var_Trapezoid;
    CIEC_REAL var_Ts;
    CIEC_BOOL var_Reset;

    CIEC_REAL var_Out;

    CIEC_REAL var_conn_Out;

    CEventConnection conn_CNF;

    CDataConnection *conn_In;
    CDataConnection *conn_OutMax;
    CDataConnection *conn_OutMin;
    CDataConnection *conn_InitValue;
    CDataConnection *conn_Trapezoid;
    CDataConnection *conn_Ts;
    CDataConnection *conn_Reset;

    CDataConnection conn_Out;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paIn, const CIEC_REAL &paOutMax, const CIEC_REAL &paOutMin, const CIEC_REAL &paInitValue, const CIEC_BOOL &paTrapezoid, const CIEC_REAL &paTs, const CIEC_BOOL &paReset, CIEC_REAL &paOut) {
      var_In = paIn;
      var_OutMax = paOutMax;
      var_OutMin = paOutMin;
      var_InitValue = paInitValue;
      var_Trapezoid = paTrapezoid;
      var_Ts = paTs;
      var_Reset = paReset;
      executeEvent(scmEventREQID, nullptr);
      paOut = var_Out;
    }

    void operator()(const CIEC_REAL &paIn, const CIEC_REAL &paOutMax, const CIEC_REAL &paOutMin, const CIEC_REAL &paInitValue, const CIEC_BOOL &paTrapezoid, const CIEC_REAL &paTs, const CIEC_BOOL &paReset, CIEC_REAL &paOut) {
      evt_REQ(paIn, paOutMax, paOutMin, paInitValue, paTrapezoid, paTs, paReset, paOut);
    }
};

