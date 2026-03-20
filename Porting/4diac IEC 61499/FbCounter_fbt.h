/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbCounter
 *** Description: Счетчик импульсов.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_dint.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbCounter final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbCounter)

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

    CIEC_BOOL var_INCPrevios;
    CIEC_BOOL var_DECPrevios;

    static const CIEC_DINT var_const_LIMIT_MAX;
    static const CIEC_DINT var_const_LIMIT_MIN;

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbCounter(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_BOOL var_INC;
    CIEC_BOOL var_DEC;
    CIEC_BOOL var_RESET;
    CIEC_BOOL var_SETVALUE;
    CIEC_DINT var_VALUE;

    CIEC_DINT var_CNT;
    CIEC_BOOL var_OVERFLOW;

    CIEC_DINT var_conn_CNT;
    CIEC_BOOL var_conn_OVERFLOW;

    CEventConnection conn_CNF;

    CDataConnection *conn_INC;
    CDataConnection *conn_DEC;
    CDataConnection *conn_RESET;
    CDataConnection *conn_SETVALUE;
    CDataConnection *conn_VALUE;

    CDataConnection conn_CNT;
    CDataConnection conn_OVERFLOW;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_BOOL &paINC, const CIEC_BOOL &paDEC, const CIEC_BOOL &paRESET, const CIEC_BOOL &paSETVALUE, const CIEC_DINT &paVALUE, CIEC_DINT &paCNT, CIEC_BOOL &paOVERFLOW) {
      var_INC = paINC;
      var_DEC = paDEC;
      var_RESET = paRESET;
      var_SETVALUE = paSETVALUE;
      var_VALUE = paVALUE;
      executeEvent(scmEventREQID, nullptr);
      paCNT = var_CNT;
      paOVERFLOW = var_OVERFLOW;
    }

    void operator()(const CIEC_BOOL &paINC, const CIEC_BOOL &paDEC, const CIEC_BOOL &paRESET, const CIEC_BOOL &paSETVALUE, const CIEC_DINT &paVALUE, CIEC_DINT &paCNT, CIEC_BOOL &paOVERFLOW) {
      evt_REQ(paINC, paDEC, paRESET, paSETVALUE, paVALUE, paCNT, paOVERFLOW);
    }
};

