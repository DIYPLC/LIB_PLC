/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FbBitsToWord
 *** Description: Преобразование 16 бит в слово.
 *** Version:
 ***     2.2: 2026-03-20/VA - LIB_PLC -
 *************************************************************************/

#pragma once

#include "core/simplefb.h"
#include "core/datatypes/forte_bool.h"
#include "core/datatypes/forte_word.h"
#include "core/iec61131_functions.h"
#include "core/datatypes/forte_array_common.h"
#include "core/datatypes/forte_array.h"
#include "core/datatypes/forte_array_fixed.h"
#include "core/datatypes/forte_array_variable.h"

class FORTE_FbBitsToWord final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_FbBitsToWord)

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

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_REQ(void);

    void enterStateREQ(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_FbBitsToWord(CStringDictionary::TStringId paInstanceNameId, forte::core::CFBContainer &paContainer);

    CIEC_BOOL var_In0;
    CIEC_BOOL var_In1;
    CIEC_BOOL var_In2;
    CIEC_BOOL var_In3;
    CIEC_BOOL var_In4;
    CIEC_BOOL var_In5;
    CIEC_BOOL var_In6;
    CIEC_BOOL var_In7;
    CIEC_BOOL var_In8;
    CIEC_BOOL var_In9;
    CIEC_BOOL var_In10;
    CIEC_BOOL var_In11;
    CIEC_BOOL var_In12;
    CIEC_BOOL var_In13;
    CIEC_BOOL var_In14;
    CIEC_BOOL var_In15;

    CIEC_WORD var_Out;

    CIEC_WORD var_conn_Out;

    CEventConnection conn_CNF;

    CDataConnection *conn_In0;
    CDataConnection *conn_In1;
    CDataConnection *conn_In2;
    CDataConnection *conn_In3;
    CDataConnection *conn_In4;
    CDataConnection *conn_In5;
    CDataConnection *conn_In6;
    CDataConnection *conn_In7;
    CDataConnection *conn_In8;
    CDataConnection *conn_In9;
    CDataConnection *conn_In10;
    CDataConnection *conn_In11;
    CDataConnection *conn_In12;
    CDataConnection *conn_In13;
    CDataConnection *conn_In14;
    CDataConnection *conn_In15;

    CDataConnection conn_Out;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_REQ(const CIEC_BOOL &paIn0, const CIEC_BOOL &paIn1, const CIEC_BOOL &paIn2, const CIEC_BOOL &paIn3, const CIEC_BOOL &paIn4, const CIEC_BOOL &paIn5, const CIEC_BOOL &paIn6, const CIEC_BOOL &paIn7, const CIEC_BOOL &paIn8, const CIEC_BOOL &paIn9, const CIEC_BOOL &paIn10, const CIEC_BOOL &paIn11, const CIEC_BOOL &paIn12, const CIEC_BOOL &paIn13, const CIEC_BOOL &paIn14, const CIEC_BOOL &paIn15, CIEC_WORD &paOut) {
      var_In0 = paIn0;
      var_In1 = paIn1;
      var_In2 = paIn2;
      var_In3 = paIn3;
      var_In4 = paIn4;
      var_In5 = paIn5;
      var_In6 = paIn6;
      var_In7 = paIn7;
      var_In8 = paIn8;
      var_In9 = paIn9;
      var_In10 = paIn10;
      var_In11 = paIn11;
      var_In12 = paIn12;
      var_In13 = paIn13;
      var_In14 = paIn14;
      var_In15 = paIn15;
      executeEvent(scmEventREQID, nullptr);
      paOut = var_Out;
    }

    void operator()(const CIEC_BOOL &paIn0, const CIEC_BOOL &paIn1, const CIEC_BOOL &paIn2, const CIEC_BOOL &paIn3, const CIEC_BOOL &paIn4, const CIEC_BOOL &paIn5, const CIEC_BOOL &paIn6, const CIEC_BOOL &paIn7, const CIEC_BOOL &paIn8, const CIEC_BOOL &paIn9, const CIEC_BOOL &paIn10, const CIEC_BOOL &paIn11, const CIEC_BOOL &paIn12, const CIEC_BOOL &paIn13, const CIEC_BOOL &paIn14, const CIEC_BOOL &paIn15, CIEC_WORD &paOut) {
      evt_REQ(paIn0, paIn1, paIn2, paIn3, paIn4, paIn5, paIn6, paIn7, paIn8, paIn9, paIn10, paIn11, paIn12, paIn13, paIn14, paIn15, paOut);
    }
};

