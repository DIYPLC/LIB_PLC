/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbDispersion
 *** Description: Дисперсия PV.
 *** Version:
 ***     1.1: 2026-03-22/VA - LIB_PLC -
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

class FORTE_FbDispersion final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbDispersion)

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

    CIEC_ARRAY_FIXED<CIEC_REAL, 0, 99> var_Buffer1;
    CIEC_REAL var_Summator;

    static const CIEC_INT var_const_NUMBER;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbDispersion(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_REAL var_In;

    CIEC_REAL var_Variance;
    CIEC_REAL var_Deviation;
    CIEC_REAL var_Mean;

    CIEC_REAL var_conn_Variance;
    CIEC_REAL var_conn_Deviation;
    CIEC_REAL var_conn_Mean;

    CEventConnection conn_CNF;

    CDataConnection *conn_In;

    CDataConnection conn_Variance;
    CDataConnection conn_Deviation;
    CDataConnection conn_Mean;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_REAL &paIn, CIEC_REAL &paVariance, CIEC_REAL &paDeviation, CIEC_REAL &paMean) {
      var_In = paIn;
      executeEvent(scmEventREQID, nullptr);
      paVariance = var_Variance;
      paDeviation = var_Deviation;
      paMean = var_Mean;
    }

    void operator()(const CIEC_REAL &paIn, CIEC_REAL &paVariance, CIEC_REAL &paDeviation, CIEC_REAL &paMean) {
      evt_REQ(paIn, paVariance, paDeviation, paMean);
    }
};

