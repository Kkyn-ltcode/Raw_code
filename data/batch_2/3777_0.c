void proto_register_h245 ( void ) {
 static hf_register_info hf [ ] = {
 {
 & hf_h245_pdu_type , {
 "PDU Type" , "h245.pdu_type" , FT_UINT32 , BASE_DEC , VALS ( h245_MultimediaSystemControlMessage_vals ) , 0 , "Type of H.245 PDU" , HFILL }
 }
 , {
 & hf_h245Manufacturer , {
 "H.245 Manufacturer" , "h245.Manufacturer" , FT_UINT32 , BASE_HEX , VALS ( H221ManufacturerCode_vals ) , 0 , "h245.H.221 Manufacturer" , HFILL }
 }
 , {
 & hf_h245_subMessageIdentifier_standard , {
 "subMessageIdentifier" , "h245.subMessageIdentifier.standard" , FT_UINT32 , BASE_DEC , VALS ( h245_h239subMessageIdentifier_vals ) , 0 , NULL , HFILL }
 }
 , # line 1 "../../asn1/h245/packet-h245-hfarr.c" {
 & hf_h245_OpenLogicalChannel_PDU , {
 "OpenLogicalChannel" , "h245.OpenLogicalChannel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_request , {
 "request" , "h245.request" , FT_UINT32 , BASE_DEC , VALS ( h245_RequestMessage_vals ) , 0 , "RequestMessage" , HFILL }
 }
 , {
 & hf_h245_response , {
 "response" , "h245.response" , FT_UINT32 , BASE_DEC , VALS ( h245_ResponseMessage_vals ) , 0 , "ResponseMessage" , HFILL }
 }
 , {
 & hf_h245_command , {
 "command" , "h245.command" , FT_UINT32 , BASE_DEC , VALS ( h245_CommandMessage_vals ) , 0 , "CommandMessage" , HFILL }
 }
 , {
 & hf_h245_indication , {
 "indication" , "h245.indication" , FT_UINT32 , BASE_DEC , VALS ( h245_IndicationMessage_vals ) , 0 , "IndicationMessage" , HFILL }
 }
 , {
 & hf_h245_nonStandardMsg , {
 "nonStandard" , "h245.nonStandard_element" , FT_NONE , BASE_NONE , NULL , 0 , "NonStandardMessage" , HFILL }
 }
 , {
 & hf_h245_masterSlaveDetermination , {
 "masterSlaveDetermination" , "h245.masterSlaveDetermination_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalCapabilitySet , {
 "terminalCapabilitySet" , "h245.terminalCapabilitySet_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_openLogicalChannel , {
 "openLogicalChannel" , "h245.openLogicalChannel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_closeLogicalChannel , {
 "closeLogicalChannel" , "h245.closeLogicalChannel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestChannelClose , {
 "requestChannelClose" , "h245.requestChannelClose_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexEntrySend , {
 "multiplexEntrySend" , "h245.multiplexEntrySend_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestMultiplexEntry , {
 "requestMultiplexEntry" , "h245.requestMultiplexEntry_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestMode , {
 "requestMode" , "h245.requestMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_roundTripDelayRequest , {
 "roundTripDelayRequest" , "h245.roundTripDelayRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maintenanceLoopRequest , {
 "maintenanceLoopRequest" , "h245.maintenanceLoopRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_communicationModeRequest , {
 "communicationModeRequest" , "h245.communicationModeRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_conferenceRequest , {
 "conferenceRequest" , "h245.conferenceRequest" , FT_UINT32 , BASE_DEC , VALS ( h245_ConferenceRequest_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multilinkRequest , {
 "multilinkRequest" , "h245.multilinkRequest" , FT_UINT32 , BASE_DEC , VALS ( h245_MultilinkRequest_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_logicalChannelRateRequest , {
 "logicalChannelRateRequest" , "h245.logicalChannelRateRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericRequest , {
 "genericRequest" , "h245.genericRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericMessage" , HFILL }
 }
 , {
 & hf_h245_masterSlaveDeterminationAck , {
 "masterSlaveDeterminationAck" , "h245.masterSlaveDeterminationAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_masterSlaveDeterminationReject , {
 "masterSlaveDeterminationReject" , "h245.masterSlaveDeterminationReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalCapabilitySetAck , {
 "terminalCapabilitySetAck" , "h245.terminalCapabilitySetAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalCapabilitySetReject , {
 "terminalCapabilitySetReject" , "h245.terminalCapabilitySetReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_openLogicalChannelAck , {
 "openLogicalChannelAck" , "h245.openLogicalChannelAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_openLogicalChannelReject , {
 "openLogicalChannelReject" , "h245.openLogicalChannelReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_closeLogicalChannelAck , {
 "closeLogicalChannelAck" , "h245.closeLogicalChannelAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestChannelCloseAck , {
 "requestChannelCloseAck" , "h245.requestChannelCloseAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestChannelCloseReject , {
 "requestChannelCloseReject" , "h245.requestChannelCloseReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexEntrySendAck , {
 "multiplexEntrySendAck" , "h245.multiplexEntrySendAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexEntrySendReject , {
 "multiplexEntrySendReject" , "h245.multiplexEntrySendReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestMultiplexEntryAck , {
 "requestMultiplexEntryAck" , "h245.requestMultiplexEntryAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestMultiplexEntryReject , {
 "requestMultiplexEntryReject" , "h245.requestMultiplexEntryReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestModeAck , {
 "requestModeAck" , "h245.requestModeAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestModeReject , {
 "requestModeReject" , "h245.requestModeReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_roundTripDelayResponse , {
 "roundTripDelayResponse" , "h245.roundTripDelayResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maintenanceLoopAck , {
 "maintenanceLoopAck" , "h245.maintenanceLoopAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maintenanceLoopReject , {
 "maintenanceLoopReject" , "h245.maintenanceLoopReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_communicationModeResponse , {
 "communicationModeResponse" , "h245.communicationModeResponse" , FT_UINT32 , BASE_DEC , VALS ( h245_CommunicationModeResponse_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_conferenceResponse , {
 "conferenceResponse" , "h245.conferenceResponse" , FT_UINT32 , BASE_DEC , VALS ( h245_ConferenceResponse_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multilinkResponse , {
 "multilinkResponse" , "h245.multilinkResponse" , FT_UINT32 , BASE_DEC , VALS ( h245_MultilinkResponse_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_logicalChannelRateAcknowledge , {
 "logicalChannelRateAcknowledge" , "h245.logicalChannelRateAcknowledge_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_logicalChannelRateReject , {
 "logicalChannelRateReject" , "h245.logicalChannelRateReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericResponse , {
 "genericResponse" , "h245.genericResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericMessage" , HFILL }
 }
 , {
 & hf_h245_maintenanceLoopOffCommand , {
 "maintenanceLoopOffCommand" , "h245.maintenanceLoopOffCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sendTerminalCapabilitySet , {
 "sendTerminalCapabilitySet" , "h245.sendTerminalCapabilitySet" , FT_UINT32 , BASE_DEC , VALS ( h245_SendTerminalCapabilitySet_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptionCommand , {
 "encryptionCommand" , "h245.encryptionCommand" , FT_UINT32 , BASE_DEC , VALS ( h245_EncryptionCommand_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_flowControlCommand , {
 "flowControlCommand" , "h245.flowControlCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_endSessionCommand , {
 "endSessionCommand" , "h245.endSessionCommand" , FT_UINT32 , BASE_DEC , VALS ( h245_EndSessionCommand_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_miscellaneousCommand , {
 "miscellaneousCommand" , "h245.miscellaneousCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_communicationModeCommand , {
 "communicationModeCommand" , "h245.communicationModeCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_conferenceCommand , {
 "conferenceCommand" , "h245.conferenceCommand" , FT_UINT32 , BASE_DEC , VALS ( h245_ConferenceCommand_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h223MultiplexReconfiguration , {
 "h223MultiplexReconfiguration" , "h245.h223MultiplexReconfiguration" , FT_UINT32 , BASE_DEC , VALS ( h245_H223MultiplexReconfiguration_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_newATMVCCommand , {
 "newATMVCCommand" , "h245.newATMVCCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mobileMultilinkReconfigurationCommand , {
 "mobileMultilinkReconfigurationCommand" , "h245.mobileMultilinkReconfigurationCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericCommand , {
 "genericCommand" , "h245.genericCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericMessage" , HFILL }
 }
 , {
 & hf_h245_functionNotUnderstood , {
 "functionNotUnderstood" , "h245.functionNotUnderstood" , FT_UINT32 , BASE_DEC , VALS ( h245_FunctionNotUnderstood_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_masterSlaveDeterminationRelease , {
 "masterSlaveDeterminationRelease" , "h245.masterSlaveDeterminationRelease_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalCapabilitySetRelease , {
 "terminalCapabilitySetRelease" , "h245.terminalCapabilitySetRelease_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_openLogicalChannelConfirm , {
 "openLogicalChannelConfirm" , "h245.openLogicalChannelConfirm_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestChannelCloseRelease , {
 "requestChannelCloseRelease" , "h245.requestChannelCloseRelease_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexEntrySendRelease , {
 "multiplexEntrySendRelease" , "h245.multiplexEntrySendRelease_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestMultiplexEntryRelease , {
 "requestMultiplexEntryRelease" , "h245.requestMultiplexEntryRelease_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestModeRelease , {
 "requestModeRelease" , "h245.requestModeRelease_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_miscellaneousIndication , {
 "miscellaneousIndication" , "h245.miscellaneousIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_jitterIndication , {
 "jitterIndication" , "h245.jitterIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h223SkewIndication , {
 "h223SkewIndication" , "h245.h223SkewIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_newATMVCIndication , {
 "newATMVCIndication" , "h245.newATMVCIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_userInput , {
 "userInput" , "h245.userInput" , FT_UINT32 , BASE_DEC , VALS ( h245_UserInputIndication_vals ) , 0 , "UserInputIndication" , HFILL }
 }
 , {
 & hf_h245_h2250MaximumSkewIndication , {
 "h2250MaximumSkewIndication" , "h245.h2250MaximumSkewIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mcLocationIndication , {
 "mcLocationIndication" , "h245.mcLocationIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_conferenceIndication , {
 "conferenceIndication" , "h245.conferenceIndication" , FT_UINT32 , BASE_DEC , VALS ( h245_ConferenceIndication_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_vendorIdentification , {
 "vendorIdentification" , "h245.vendorIdentification_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_functionNotSupported , {
 "functionNotSupported" , "h245.functionNotSupported_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multilinkIndication , {
 "multilinkIndication" , "h245.multilinkIndication" , FT_UINT32 , BASE_DEC , VALS ( h245_MultilinkIndication_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_logicalChannelRateRelease , {
 "logicalChannelRateRelease" , "h245.logicalChannelRateRelease_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_flowControlIndication , {
 "flowControlIndication" , "h245.flowControlIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mobileMultilinkReconfigurationIndication , {
 "mobileMultilinkReconfigurationIndication" , "h245.mobileMultilinkReconfigurationIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericIndication , {
 "genericIndication" , "h245.genericIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericMessage" , HFILL }
 }
 , {
 & hf_h245_messageIdentifier , {
 "messageIdentifier" , "h245.messageIdentifier" , FT_UINT32 , BASE_DEC , VALS ( h245_CapabilityIdentifier_vals ) , 0 , "CapabilityIdentifier" , HFILL }
 }
 , {
 & hf_h245_subMessageIdentifier , {
 "subMessageIdentifier" , "h245.subMessageIdentifier" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_messageContent , {
 "messageContent" , "h245.messageContent" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_messageContent_item , {
 "messageContent item" , "h245.messageContent_item_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_messageContent_item" , HFILL }
 }
 , {
 & hf_h245_nonStandardData , {
 "nonStandardData" , "h245.nonStandardData_element" , FT_NONE , BASE_NONE , NULL , 0 , "NonStandardParameter" , HFILL }
 }
 , {
 & hf_h245_nonStandardIdentifier , {
 "nonStandardIdentifier" , "h245.nonStandardIdentifier" , FT_UINT32 , BASE_DEC , VALS ( h245_NonStandardIdentifier_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_nsd_data , {
 "data" , "h245.data" , FT_BYTES , BASE_NONE , NULL , 0 , "T_nsd_data" , HFILL }
 }
 , {
 & hf_h245_object , {
 "object" , "h245.object" , FT_OID , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h221NonStandardID , {
 "h221NonStandard" , "h245.h221NonStandard_element" , FT_NONE , BASE_NONE , NULL , 0 , "H221NonStandardID" , HFILL }
 }
 , {
 & hf_h245_t35CountryCode , {
 "t35CountryCode" , "h245.t35CountryCode" , FT_UINT32 , BASE_DEC , VALS ( T35CountryCode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t35Extension , {
 "t35Extension" , "h245.t35Extension" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_manufacturerCode , {
 "manufacturerCode" , "h245.manufacturerCode" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalType , {
 "terminalType" , "h245.terminalType" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_statusDeterminationNumber , {
 "statusDeterminationNumber" , "h245.statusDeterminationNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_16777215" , HFILL }
 }
 , {
 & hf_h245_decision , {
 "decision" , "h245.decision" , FT_UINT32 , BASE_DEC , VALS ( h245_T_decision_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_master , {
 "master" , "h245.master_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_slave , {
 "slave" , "h245.slave_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_msd_rej_cause , {
 "cause" , "h245.cause" , FT_UINT32 , BASE_DEC , VALS ( h245_MasterSlaveDeterminationRejectCause_vals ) , 0 , "MasterSlaveDeterminationRejectCause" , HFILL }
 }
 , {
 & hf_h245_identicalNumbers , {
 "identicalNumbers" , "h245.identicalNumbers_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sequenceNumber , {
 "sequenceNumber" , "h245.sequenceNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_protocolIdentifier , {
 "protocolIdentifier" , "h245.protocolIdentifier" , FT_OID , BASE_NONE , NULL , 0 , "OBJECT_IDENTIFIER" , HFILL }
 }
 , {
 & hf_h245_multiplexCapability , {
 "multiplexCapability" , "h245.multiplexCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_MultiplexCapability_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_capabilityTable , {
 "capabilityTable" , "h245.capabilityTable" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_256_OF_CapabilityTableEntry" , HFILL }
 }
 , {
 & hf_h245_capabilityTable_item , {
 "CapabilityTableEntry" , "h245.CapabilityTableEntry_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_capabilityDescriptors , {
 "capabilityDescriptors" , "h245.capabilityDescriptors" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_256_OF_CapabilityDescriptor" , HFILL }
 }
 , {
 & hf_h245_capabilityDescriptors_item , {
 "CapabilityDescriptor" , "h245.CapabilityDescriptor_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericInformation , {
 "genericInformation" , "h245.genericInformation" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_GenericInformation" , HFILL }
 }
 , {
 & hf_h245_genericInformation_item , {
 "GenericInformation" , "h245.GenericInformation_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_capabilityTableEntryNumber , {
 "capabilityTableEntryNumber" , "h245.capabilityTableEntryNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_capability , {
 "capability" , "h245.capability" , FT_UINT32 , BASE_DEC , VALS ( h245_Capability_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_capabilityDescriptorNumber , {
 "capabilityDescriptorNumber" , "h245.capabilityDescriptorNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_simultaneousCapabilities , {
 "simultaneousCapabilities" , "h245.simultaneousCapabilities" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_256_OF_AlternativeCapabilitySet" , HFILL }
 }
 , {
 & hf_h245_simultaneousCapabilities_item , {
 "AlternativeCapabilitySet" , "h245.AlternativeCapabilitySet" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_AlternativeCapabilitySet_item , {
 "alternativeCapability" , "h245.CapabilityTableEntryNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "CapabilityTableEntryNumber" , HFILL }
 }
 , {
 & hf_h245_tcs_rej_cause , {
 "cause" , "h245.cause" , FT_UINT32 , BASE_DEC , VALS ( h245_TerminalCapabilitySetRejectCause_vals ) , 0 , "TerminalCapabilitySetRejectCause" , HFILL }
 }
 , {
 & hf_h245_unspecified , {
 "unspecified" , "h245.unspecified_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_undefinedTableEntryUsed , {
 "undefinedTableEntryUsed" , "h245.undefinedTableEntryUsed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_descriptorCapacityExceeded , {
 "descriptorCapacityExceeded" , "h245.descriptorCapacityExceeded_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_tableEntryCapacityExceeded , {
 "tableEntryCapacityExceeded" , "h245.tableEntryCapacityExceeded" , FT_UINT32 , BASE_DEC , VALS ( h245_T_tableEntryCapacityExceeded_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_highestEntryNumberProcessed , {
 "highestEntryNumberProcessed" , "h245.highestEntryNumberProcessed" , FT_UINT32 , BASE_DEC , NULL , 0 , "CapabilityTableEntryNumber" , HFILL }
 }
 , {
 & hf_h245_noneProcessed , {
 "noneProcessed" , "h245.noneProcessed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_nonStandard , {
 "nonStandard" , "h245.nonStandard_element" , FT_NONE , BASE_NONE , NULL , 0 , "NonStandardParameter" , HFILL }
 }
 , {
 & hf_h245_receiveVideoCapability , {
 "receiveVideoCapability" , "h245.receiveVideoCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_VideoCapability_vals ) , 0 , "VideoCapability" , HFILL }
 }
 , {
 & hf_h245_transmitVideoCapability , {
 "transmitVideoCapability" , "h245.transmitVideoCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_VideoCapability_vals ) , 0 , "VideoCapability" , HFILL }
 }
 , {
 & hf_h245_receiveAndTransmitVideoCapability , {
 "receiveAndTransmitVideoCapability" , "h245.receiveAndTransmitVideoCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_VideoCapability_vals ) , 0 , "VideoCapability" , HFILL }
 }
 , {
 & hf_h245_receiveAudioCapability , {
 "receiveAudioCapability" , "h245.receiveAudioCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_AudioCapability_vals ) , 0 , "AudioCapability" , HFILL }
 }
 , {
 & hf_h245_transmitAudioCapability , {
 "transmitAudioCapability" , "h245.transmitAudioCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_AudioCapability_vals ) , 0 , "AudioCapability" , HFILL }
 }
 , {
 & hf_h245_receiveAndTransmitAudioCapability , {
 "receiveAndTransmitAudioCapability" , "h245.receiveAndTransmitAudioCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_AudioCapability_vals ) , 0 , "AudioCapability" , HFILL }
 }
 , {
 & hf_h245_receiveDataApplicationCapability , {
 "receiveDataApplicationCapability" , "h245.receiveDataApplicationCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "DataApplicationCapability" , HFILL }
 }
 , {
 & hf_h245_transmitDataApplicationCapability , {
 "transmitDataApplicationCapability" , "h245.transmitDataApplicationCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "DataApplicationCapability" , HFILL }
 }
 , {
 & hf_h245_receiveAndTransmitDataApplicationCapability , {
 "receiveAndTransmitDataApplicationCapability" , "h245.receiveAndTransmitDataApplicationCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "DataApplicationCapability" , HFILL }
 }
 , {
 & hf_h245_h233EncryptionTransmitCapability , {
 "h233EncryptionTransmitCapability" , "h245.h233EncryptionTransmitCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_h233EncryptionReceiveCapability , {
 "h233EncryptionReceiveCapability" , "h245.h233EncryptionReceiveCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h233IVResponseTime , {
 "h233IVResponseTime" , "h245.h233IVResponseTime" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_conferenceCapability , {
 "conferenceCapability" , "h245.conferenceCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h235SecurityCapability , {
 "h235SecurityCapability" , "h245.h235SecurityCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maxPendingReplacementFor , {
 "maxPendingReplacementFor" , "h245.maxPendingReplacementFor" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_receiveUserInputCapability , {
 "receiveUserInputCapability" , "h245.receiveUserInputCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_UserInputCapability_vals ) , 0 , "UserInputCapability" , HFILL }
 }
 , {
 & hf_h245_transmitUserInputCapability , {
 "transmitUserInputCapability" , "h245.transmitUserInputCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_UserInputCapability_vals ) , 0 , "UserInputCapability" , HFILL }
 }
 , {
 & hf_h245_receiveAndTransmitUserInputCapability , {
 "receiveAndTransmitUserInputCapability" , "h245.receiveAndTransmitUserInputCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_UserInputCapability_vals ) , 0 , "UserInputCapability" , HFILL }
 }
 , {
 & hf_h245_genericControlCapability , {
 "genericControlCapability" , "h245.genericControlCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_receiveMultiplexedStreamCapability , {
 "receiveMultiplexedStreamCapability" , "h245.receiveMultiplexedStreamCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "MultiplexedStreamCapability" , HFILL }
 }
 , {
 & hf_h245_transmitMultiplexedStreamCapability , {
 "transmitMultiplexedStreamCapability" , "h245.transmitMultiplexedStreamCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "MultiplexedStreamCapability" , HFILL }
 }
 , {
 & hf_h245_receiveAndTransmitMultiplexedStreamCapability , {
 "receiveAndTransmitMultiplexedStreamCapability" , "h245.receiveAndTransmitMultiplexedStreamCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "MultiplexedStreamCapability" , HFILL }
 }
 , {
 & hf_h245_receiveRTPAudioTelephonyEventCapability , {
 "receiveRTPAudioTelephonyEventCapability" , "h245.receiveRTPAudioTelephonyEventCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "AudioTelephonyEventCapability" , HFILL }
 }
 , {
 & hf_h245_receiveRTPAudioToneCapability , {
 "receiveRTPAudioToneCapability" , "h245.receiveRTPAudioToneCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "AudioToneCapability" , HFILL }
 }
 , {
 & hf_h245_depFecCapability , {
 "depFecCapability" , "h245.depFecCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_DepFECCapability_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplePayloadStreamCapability , {
 "multiplePayloadStreamCapability" , "h245.multiplePayloadStreamCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fecCapability , {
 "fecCapability" , "h245.fecCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_redundancyEncodingCap , {
 "redundancyEncodingCap" , "h245.redundancyEncodingCap_element" , FT_NONE , BASE_NONE , NULL , 0 , "RedundancyEncodingCapability" , HFILL }
 }
 , {
 & hf_h245_oneOfCapabilities , {
 "oneOfCapabilities" , "h245.oneOfCapabilities" , FT_UINT32 , BASE_DEC , NULL , 0 , "AlternativeCapabilitySet" , HFILL }
 }
 , {
 & hf_h245_encryptionAuthenticationAndIntegrity , {
 "encryptionAuthenticationAndIntegrity" , "h245.encryptionAuthenticationAndIntegrity_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mediaCapability , {
 "mediaCapability" , "h245.mediaCapability" , FT_UINT32 , BASE_DEC , NULL , 0 , "CapabilityTableEntryNumber" , HFILL }
 }
 , {
 & hf_h245_h222Capability , {
 "h222Capability" , "h245.h222Capability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h223Capability , {
 "h223Capability" , "h245.h223Capability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v76Capability , {
 "v76Capability" , "h245.v76Capability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h2250Capability , {
 "h2250Capability" , "h245.h2250Capability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericMultiplexCapability , {
 "genericMultiplexCapability" , "h245.genericMultiplexCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_numberOfVCs , {
 "numberOfVCs" , "h245.numberOfVCs" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_vcCapability , {
 "vcCapability" , "h245.vcCapability" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_OF_VCCapability" , HFILL }
 }
 , {
 & hf_h245_vcCapability_item , {
 "VCCapability" , "h245.VCCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_aal1 , {
 "aal1" , "h245.aal1_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_nullClockRecovery , {
 "nullClockRecovery" , "h245.nullClockRecovery" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_srtsClockRecovery_bool , {
 "srtsClockRecovery" , "h245.srtsClockRecovery" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_adaptiveClockRecovery , {
 "adaptiveClockRecovery" , "h245.adaptiveClockRecovery" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_nullErrorCorrection , {
 "nullErrorCorrection" , "h245.nullErrorCorrection" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_longInterleaver , {
 "longInterleaver" , "h245.longInterleaver" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_shortInterleaver , {
 "shortInterleaver" , "h245.shortInterleaver" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_errorCorrectionOnly , {
 "errorCorrectionOnly" , "h245.errorCorrectionOnly" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_structuredDataTransfer , {
 "structuredDataTransfer" , "h245.structuredDataTransfer" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_partiallyFilledCells , {
 "partiallyFilledCells" , "h245.partiallyFilledCells" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_aal5 , {
 "aal5" , "h245.aal5_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_forwardMaximumSDUSize , {
 "forwardMaximumSDUSize" , "h245.forwardMaximumSDUSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_backwardMaximumSDUSize , {
 "backwardMaximumSDUSize" , "h245.backwardMaximumSDUSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_transportStream_bool , {
 "transportStream" , "h245.transportStream" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_programStream , {
 "programStream" , "h245.programStream" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_availableBitRates , {
 "availableBitRates" , "h245.availableBitRates_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_avb_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_Avb_type_vals ) , 0 , "Avb_type" , HFILL }
 }
 , {
 & hf_h245_singleBitRate , {
 "singleBitRate" , "h245.singleBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65535" , HFILL }
 }
 , {
 & hf_h245_rangeOfBitRates , {
 "rangeOfBitRates" , "h245.rangeOfBitRates_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_lowerBitRate , {
 "lowerBitRate" , "h245.lowerBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65535" , HFILL }
 }
 , {
 & hf_h245_higherBitRate , {
 "higherBitRate" , "h245.higherBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65535" , HFILL }
 }
 , {
 & hf_h245_aal1ViaGateway , {
 "aal1ViaGateway" , "h245.aal1ViaGateway_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_gatewayAddress , {
 "gatewayAddress" , "h245.gatewayAddress" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_256_OF_Q2931Address" , HFILL }
 }
 , {
 & hf_h245_gatewayAddress_item , {
 "Q2931Address" , "h245.Q2931Address_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_srtsClockRecoveryflag , {
 "srtsClockRecovery" , "h245.srtsClockRecovery" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_transportWithI_frames , {
 "transportWithI-frames" , "h245.transportWithI_frames" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoWithAL1 , {
 "videoWithAL1" , "h245.videoWithAL1" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoWithAL2 , {
 "videoWithAL2" , "h245.videoWithAL2" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoWithAL3 , {
 "videoWithAL3" , "h245.videoWithAL3" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioWithAL1 , {
 "audioWithAL1" , "h245.audioWithAL1" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioWithAL2 , {
 "audioWithAL2" , "h245.audioWithAL2" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioWithAL3 , {
 "audioWithAL3" , "h245.audioWithAL3" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dataWithAL1 , {
 "dataWithAL1" , "h245.dataWithAL1" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dataWithAL2 , {
 "dataWithAL2" , "h245.dataWithAL2" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dataWithAL3 , {
 "dataWithAL3" , "h245.dataWithAL3" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_maximumAl2SDUSize , {
 "maximumAl2SDUSize" , "h245.maximumAl2SDUSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_maximumAl3SDUSize , {
 "maximumAl3SDUSize" , "h245.maximumAl3SDUSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_maximumDelayJitter , {
 "maximumDelayJitter" , "h245.maximumDelayJitter" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_1023" , HFILL }
 }
 , {
 & hf_h245_h223MultiplexTableCapability , {
 "h223MultiplexTableCapability" , "h245.h223MultiplexTableCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_T_h223MultiplexTableCapability_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_basic , {
 "basic" , "h245.basic_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_enhanced , {
 "enhanced" , "h245.enhanced_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maximumNestingDepth , {
 "maximumNestingDepth" , "h245.maximumNestingDepth" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_15" , HFILL }
 }
 , {
 & hf_h245_maximumElementListSize , {
 "maximumElementListSize" , "h245.maximumElementListSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_2_255" , HFILL }
 }
 , {
 & hf_h245_maximumSubElementListSize , {
 "maximumSubElementListSize" , "h245.maximumSubElementListSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_2_255" , HFILL }
 }
 , {
 & hf_h245_maxMUXPDUSizeCapability , {
 "maxMUXPDUSizeCapability" , "h245.maxMUXPDUSizeCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_nsrpSupport , {
 "nsrpSupport" , "h245.nsrpSupport" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_mobileOperationTransmitCapability , {
 "mobileOperationTransmitCapability" , "h245.mobileOperationTransmitCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_modeChangeCapability , {
 "modeChangeCapability" , "h245.modeChangeCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_h223AnnexA , {
 "h223AnnexA" , "h245.h223AnnexA" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_h223AnnexADoubleFlagFlag , {
 "h223AnnexADoubleFlag" , "h245.h223AnnexADoubleFlag" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_h223AnnexB , {
 "h223AnnexB" , "h245.h223AnnexB" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_h223AnnexBwithHeader , {
 "h223AnnexBwithHeader" , "h245.h223AnnexBwithHeader" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_h223AnnexCCapability , {
 "h223AnnexCCapability" , "h245.h223AnnexCCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_bitRate_1_19200 , {
 "bitRate" , "h245.bitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_19200" , HFILL }
 }
 , {
 & hf_h245_mobileMultilinkFrameCapability , {
 "mobileMultilinkFrameCapability" , "h245.mobileMultilinkFrameCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maximumSampleSize , {
 "maximumSampleSize" , "h245.maximumSampleSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_maximumPayloadLength , {
 "maximumPayloadLength" , "h245.maximumPayloadLength" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65025" , HFILL }
 }
 , {
 & hf_h245_videoWithAL1M , {
 "videoWithAL1M" , "h245.videoWithAL1M" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoWithAL2M , {
 "videoWithAL2M" , "h245.videoWithAL2M" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoWithAL3M , {
 "videoWithAL3M" , "h245.videoWithAL3M" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioWithAL1M , {
 "audioWithAL1M" , "h245.audioWithAL1M" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioWithAL2M , {
 "audioWithAL2M" , "h245.audioWithAL2M" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioWithAL3M , {
 "audioWithAL3M" , "h245.audioWithAL3M" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dataWithAL1M , {
 "dataWithAL1M" , "h245.dataWithAL1M" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dataWithAL2M , {
 "dataWithAL2M" , "h245.dataWithAL2M" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dataWithAL3M , {
 "dataWithAL3M" , "h245.dataWithAL3M" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_alpduInterleaving , {
 "alpduInterleaving" , "h245.alpduInterleaving" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_maximumAL1MPDUSize , {
 "maximumAL1MPDUSize" , "h245.maximumAL1MPDUSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_maximumAL2MSDUSize , {
 "maximumAL2MSDUSize" , "h245.maximumAL2MSDUSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_maximumAL3MSDUSize , {
 "maximumAL3MSDUSize" , "h245.maximumAL3MSDUSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_rsCodeCapability , {
 "rsCodeCapability" , "h245.rsCodeCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_suspendResumeCapabilitywAddress , {
 "suspendResumeCapabilitywAddress" , "h245.suspendResumeCapabilitywAddress" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_suspendResumeCapabilitywoAddress , {
 "suspendResumeCapabilitywoAddress" , "h245.suspendResumeCapabilitywoAddress" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_rejCapability , {
 "rejCapability" , "h245.rejCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_sREJCapability , {
 "sREJCapability" , "h245.sREJCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_mREJCapability , {
 "mREJCapability" , "h245.mREJCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_crc8bitCapability , {
 "crc8bitCapability" , "h245.crc8bitCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_crc16bitCapability , {
 "crc16bitCapability" , "h245.crc16bitCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_crc32bitCapability , {
 "crc32bitCapability" , "h245.crc32bitCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_uihCapability , {
 "uihCapability" , "h245.uihCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_numOfDLCS , {
 "numOfDLCS" , "h245.numOfDLCS" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_2_8191" , HFILL }
 }
 , {
 & hf_h245_twoOctetAddressFieldCapability , {
 "twoOctetAddressFieldCapability" , "h245.twoOctetAddressFieldCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_loopBackTestCapability , {
 "loopBackTestCapability" , "h245.loopBackTestCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_n401Capability , {
 "n401Capability" , "h245.n401Capability" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4095" , HFILL }
 }
 , {
 & hf_h245_maxWindowSizeCapability , {
 "maxWindowSizeCapability" , "h245.maxWindowSizeCapability" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_127" , HFILL }
 }
 , {
 & hf_h245_v75Capability , {
 "v75Capability" , "h245.v75Capability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioHeader , {
 "audioHeader" , "h245.audioHeader" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_maximumAudioDelayJitter , {
 "maximumAudioDelayJitter" , "h245.maximumAudioDelayJitter" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_1023" , HFILL }
 }
 , {
 & hf_h245_receiveMultipointCapability , {
 "receiveMultipointCapability" , "h245.receiveMultipointCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "MultipointCapability" , HFILL }
 }
 , {
 & hf_h245_transmitMultipointCapability , {
 "transmitMultipointCapability" , "h245.transmitMultipointCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "MultipointCapability" , HFILL }
 }
 , {
 & hf_h245_receiveAndTransmitMultipointCapability , {
 "receiveAndTransmitMultipointCapability" , "h245.receiveAndTransmitMultipointCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "MultipointCapability" , HFILL }
 }
 , {
 & hf_h245_mcCapability , {
 "mcCapability" , "h245.mcCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_centralizedConferenceMC , {
 "centralizedConferenceMC" , "h245.centralizedConferenceMC" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_decentralizedConferenceMC , {
 "decentralizedConferenceMC" , "h245.decentralizedConferenceMC" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_rtcpVideoControlCapability , {
 "rtcpVideoControlCapability" , "h245.rtcpVideoControlCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_mediaPacketizationCapability , {
 "mediaPacketizationCapability" , "h245.mediaPacketizationCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_transportCapability , {
 "transportCapability" , "h245.transportCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_redundancyEncodingCapability , {
 "redundancyEncodingCapability" , "h245.redundancyEncodingCapability" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_SIZE_1_256_OF_RedundancyEncodingCapability" , HFILL }
 }
 , {
 & hf_h245_redundancyEncodingCapability_item , {
 "RedundancyEncodingCapability" , "h245.RedundancyEncodingCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_logicalChannelSwitchingCapability , {
 "logicalChannelSwitchingCapability" , "h245.logicalChannelSwitchingCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_t120DynamicPortCapability , {
 "t120DynamicPortCapability" , "h245.t120DynamicPortCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_h261aVideoPacketization , {
 "h261aVideoPacketization" , "h245.h261aVideoPacketization" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_rtpPayloadTypes , {
 "rtpPayloadType" , "h245.rtpPayloadType" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_SIZE_1_256_OF_RTPPayloadType" , HFILL }
 }
 , {
 & hf_h245_rtpPayloadTypes_item , {
 "RTPPayloadType" , "h245.RTPPayloadType_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_qosMode , {
 "qosMode" , "h245.qosMode" , FT_UINT32 , BASE_DEC , VALS ( h245_QOSMode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_tokenRate , {
 "tokenRate" , "h245.tokenRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4294967295" , HFILL }
 }
 , {
 & hf_h245_bucketSize , {
 "bucketSize" , "h245.bucketSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4294967295" , HFILL }
 }
 , {
 & hf_h245_peakRate , {
 "peakRate" , "h245.peakRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4294967295" , HFILL }
 }
 , {
 & hf_h245_minPoliced , {
 "minPoliced" , "h245.minPoliced" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4294967295" , HFILL }
 }
 , {
 & hf_h245_maxPktSize , {
 "maxPktSize" , "h245.maxPktSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4294967295" , HFILL }
 }
 , {
 & hf_h245_guaranteedQOS , {
 "guaranteedQOS" , "h245.guaranteedQOS_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_controlledLoad , {
 "controlledLoad" , "h245.controlledLoad_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maxNTUSize , {
 "maxNTUSize" , "h245.maxNTUSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_atmUBR , {
 "atmUBR" , "h245.atmUBR" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_atmrtVBR , {
 "atmrtVBR" , "h245.atmrtVBR" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_atmnrtVBR , {
 "atmnrtVBR" , "h245.atmnrtVBR" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_atmABR , {
 "atmABR" , "h245.atmABR" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_atmCBR , {
 "atmCBR" , "h245.atmCBR" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_nonStandardParameter , {
 "nonStandardParameter" , "h245.nonStandardParameter_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_value , {
 "value" , "h245.value" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_servicePrioritySignalled , {
 "servicePrioritySignalled" , "h245.servicePrioritySignalled" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_servicePriorityValue , {
 "servicePriorityValue" , "h245.servicePriorityValue_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_serviceClass , {
 "serviceClass" , "h245.serviceClass" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4095" , HFILL }
 }
 , {
 & hf_h245_serviceSubclass , {
 "serviceSubclass" , "h245.serviceSubclass" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_desired , {
 "desired" , "h245.desired_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_required , {
 "required" , "h245.required_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_class0 , {
 "class0" , "h245.class0_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_class1 , {
 "class1" , "h245.class1_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_class2 , {
 "class2" , "h245.class2_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_class3 , {
 "class3" , "h245.class3_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_class4 , {
 "class4" , "h245.class4_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_class5 , {
 "class5" , "h245.class5_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_qosType , {
 "qosType" , "h245.qosType" , FT_UINT32 , BASE_DEC , VALS ( h245_QOSType_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_qosClass , {
 "qosClass" , "h245.qosClass" , FT_UINT32 , BASE_DEC , VALS ( h245_QOSClass_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_averageRate , {
 "averageRate" , "h245.averageRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4294967295" , HFILL }
 }
 , {
 & hf_h245_burst , {
 "burst" , "h245.burst" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4294967295" , HFILL }
 }
 , {
 & hf_h245_rsvpParameters , {
 "rsvpParameters" , "h245.rsvpParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_atmParameters , {
 "atmParameters" , "h245.atmParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_localQoS , {
 "localQoS" , "h245.localQoS" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_genericTransportParameters , {
 "genericTransportParameters" , "h245.genericTransportParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_servicePriority , {
 "servicePriority" , "h245.servicePriority_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_authorizationParameter , {
 "authorizationParameter" , "h245.authorizationParameter_element" , FT_NONE , BASE_NONE , NULL , 0 , "AuthorizationParameters" , HFILL }
 }
 , {
 & hf_h245_qosDescriptor , {
 "qosDescriptor" , "h245.qosDescriptor_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dscpValue , {
 "dscpValue" , "h245.dscpValue" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_63" , HFILL }
 }
 , {
 & hf_h245_ip_UDP , {
 "ip-UDP" , "h245.ip_UDP_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_ip_TCP , {
 "ip-TCP" , "h245.ip_TCP_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_atm_AAL5_UNIDIR , {
 "atm-AAL5-UNIDIR" , "h245.atm_AAL5_UNIDIR_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_atm_AAL5_BIDIR , {
 "atm-AAL5-BIDIR" , "h245.atm_AAL5_BIDIR_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_atm_AAL5_compressed , {
 "atm-AAL5-compressed" , "h245.atm_AAL5_compressed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_variable_delta , {
 "variable-delta" , "h245.variable_delta" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_mediaTransport , {
 "mediaTransport" , "h245.mediaTransport" , FT_UINT32 , BASE_DEC , VALS ( h245_MediaTransportType_vals ) , 0 , "MediaTransportType" , HFILL }
 }
 , {
 & hf_h245_qOSCapabilities , {
 "qOSCapabilities" , "h245.qOSCapabilities" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_SIZE_1_256_OF_QOSCapability" , HFILL }
 }
 , {
 & hf_h245_qOSCapabilities_item , {
 "QOSCapability" , "h245.QOSCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mediaChannelCapabilities , {
 "mediaChannelCapabilities" , "h245.mediaChannelCapabilities" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_SIZE_1_256_OF_MediaChannelCapability" , HFILL }
 }
 , {
 & hf_h245_mediaChannelCapabilities_item , {
 "MediaChannelCapability" , "h245.MediaChannelCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_redundancyEncodingMethod , {
 "redundancyEncodingMethod" , "h245.redundancyEncodingMethod" , FT_UINT32 , BASE_DEC , VALS ( h245_RedundancyEncodingMethod_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_primaryEncoding , {
 "primaryEncoding" , "h245.primaryEncoding" , FT_UINT32 , BASE_DEC , NULL , 0 , "CapabilityTableEntryNumber" , HFILL }
 }
 , {
 & hf_h245_secondaryEncodingCapability , {
 "secondaryEncoding" , "h245.secondaryEncoding" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_SIZE_1_256_OF_CapabilityTableEntryNumber" , HFILL }
 }
 , {
 & hf_h245_secondaryEncodingCapability_item , {
 "CapabilityTableEntryNumber" , "h245.CapabilityTableEntryNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rtpAudioRedundancyEncoding , {
 "rtpAudioRedundancyEncoding" , "h245.rtpAudioRedundancyEncoding_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rtpH263VideoRedundancyEncoding , {
 "rtpH263VideoRedundancyEncoding" , "h245.rtpH263VideoRedundancyEncoding_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_numberOfThreads , {
 "numberOfThreads" , "h245.numberOfThreads" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_16" , HFILL }
 }
 , {
 & hf_h245_framesBetweenSyncPoints , {
 "framesBetweenSyncPoints" , "h245.framesBetweenSyncPoints" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_frameToThreadMapping , {
 "frameToThreadMapping" , "h245.frameToThreadMapping" , FT_UINT32 , BASE_DEC , VALS ( h245_T_frameToThreadMapping_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_roundrobin , {
 "roundrobin" , "h245.roundrobin_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_custom , {
 "custom" , "h245.custom" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_SIZE_1_256_OF_RTPH263VideoRedundancyFrameMapping" , HFILL }
 }
 , {
 & hf_h245_custom_item , {
 "RTPH263VideoRedundancyFrameMapping" , "h245.RTPH263VideoRedundancyFrameMapping_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_containedThreads , {
 "containedThreads" , "h245.containedThreads" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_containedThreads_item , {
 "containedThreads item" , "h245.containedThreads_item" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_15" , HFILL }
 }
 , {
 & hf_h245_threadNumber , {
 "threadNumber" , "h245.threadNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_15" , HFILL }
 }
 , {
 & hf_h245_frameSequence , {
 "frameSequence" , "h245.frameSequence" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_frameSequence_item , {
 "frameSequence item" , "h245.frameSequence_item" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_multicastCapability , {
 "multicastCapability" , "h245.multicastCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_multiUniCastConference , {
 "multiUniCastConference" , "h245.multiUniCastConference" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_mediaDistributionCapability , {
 "mediaDistributionCapability" , "h245.mediaDistributionCapability" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_MediaDistributionCapability" , HFILL }
 }
 , {
 & hf_h245_mediaDistributionCapability_item , {
 "MediaDistributionCapability" , "h245.MediaDistributionCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_centralizedControl , {
 "centralizedControl" , "h245.centralizedControl" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_distributedControl , {
 "distributedControl" , "h245.distributedControl" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_centralizedAudio , {
 "centralizedAudio" , "h245.centralizedAudio" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_distributedAudio , {
 "distributedAudio" , "h245.distributedAudio" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_centralizedVideo , {
 "centralizedVideo" , "h245.centralizedVideo" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_distributedVideo , {
 "distributedVideo" , "h245.distributedVideo" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_centralizedData , {
 "centralizedData" , "h245.centralizedData" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_DataApplicationCapability" , HFILL }
 }
 , {
 & hf_h245_centralizedData_item , {
 "DataApplicationCapability" , "h245.DataApplicationCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_distributedData , {
 "distributedData" , "h245.distributedData" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_DataApplicationCapability" , HFILL }
 }
 , {
 & hf_h245_distributedData_item , {
 "DataApplicationCapability" , "h245.DataApplicationCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h261VideoCapability , {
 "h261VideoCapability" , "h245.h261VideoCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h262VideoCapability , {
 "h262VideoCapability" , "h245.h262VideoCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h263VideoCapability , {
 "h263VideoCapability" , "h245.h263VideoCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_is11172VideoCapability , {
 "is11172VideoCapability" , "h245.is11172VideoCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericVideoCapability , {
 "genericVideoCapability" , "h245.genericVideoCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_extendedVideoCapability , {
 "extendedVideoCapability" , "h245.extendedVideoCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoCapability , {
 "videoCapability" , "h245.videoCapability" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_VideoCapability" , HFILL }
 }
 , {
 & hf_h245_videoCapability_item , {
 "VideoCapability" , "h245.VideoCapability" , FT_UINT32 , BASE_DEC , VALS ( h245_VideoCapability_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoCapabilityExtension , {
 "videoCapabilityExtension" , "h245.videoCapabilityExtension" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_GenericCapability" , HFILL }
 }
 , {
 & hf_h245_videoCapabilityExtension_item , {
 "GenericCapability" , "h245.GenericCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_qcifMPI_1_4 , {
 "qcifMPI" , "h245.qcifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4" , HFILL }
 }
 , {
 & hf_h245_cifMPI_1_4 , {
 "cifMPI" , "h245.cifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4" , HFILL }
 }
 , {
 & hf_h245_temporalSpatialTradeOffCapability , {
 "temporalSpatialTradeOffCapability" , "h245.temporalSpatialTradeOffCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_maxBitRate_1_19200 , {
 "maxBitRate" , "h245.maxBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_19200" , HFILL }
 }
 , {
 & hf_h245_stillImageTransmission , {
 "stillImageTransmission" , "h245.stillImageTransmission" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoBadMBsCap , {
 "videoBadMBsCap" , "h245.videoBadMBsCap" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_SPatML , {
 "profileAndLevel-SPatML" , "h245.profileAndLevel_SPatML" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_MPatLL , {
 "profileAndLevel-MPatLL" , "h245.profileAndLevel_MPatLL" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_MPatML , {
 "profileAndLevel-MPatML" , "h245.profileAndLevel_MPatML" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_MPatH_14 , {
 "profileAndLevel-MPatH-14" , "h245.profileAndLevel_MPatH_14" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_MPatHL , {
 "profileAndLevel-MPatHL" , "h245.profileAndLevel_MPatHL" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_SNRatLL , {
 "profileAndLevel-SNRatLL" , "h245.profileAndLevel_SNRatLL" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_SNRatML , {
 "profileAndLevel-SNRatML" , "h245.profileAndLevel_SNRatML" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_SpatialatH_14 , {
 "profileAndLevel-SpatialatH-14" , "h245.profileAndLevel_SpatialatH_14" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_HPatML , {
 "profileAndLevel-HPatML" , "h245.profileAndLevel_HPatML" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_HPatH_14 , {
 "profileAndLevel-HPatH-14" , "h245.profileAndLevel_HPatH_14" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_HPatHL , {
 "profileAndLevel-HPatHL" , "h245.profileAndLevel_HPatHL" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoBitRate , {
 "videoBitRate" , "h245.videoBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_1073741823" , HFILL }
 }
 , {
 & hf_h245_vbvBufferSize , {
 "vbvBufferSize" , "h245.vbvBufferSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_262143" , HFILL }
 }
 , {
 & hf_h245_samplesPerLine , {
 "samplesPerLine" , "h245.samplesPerLine" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_16383" , HFILL }
 }
 , {
 & hf_h245_linesPerFrame , {
 "linesPerFrame" , "h245.linesPerFrame" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_16383" , HFILL }
 }
 , {
 & hf_h245_framesPerSecond , {
 "framesPerSecond" , "h245.framesPerSecond" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_15" , HFILL }
 }
 , {
 & hf_h245_luminanceSampleRate , {
 "luminanceSampleRate" , "h245.luminanceSampleRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4294967295" , HFILL }
 }
 , {
 & hf_h245_sqcifMPI_1_32 , {
 "sqcifMPI" , "h245.sqcifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_32" , HFILL }
 }
 , {
 & hf_h245_qcifMPI , {
 "qcifMPI" , "h245.qcifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_32" , HFILL }
 }
 , {
 & hf_h245_cifMPI , {
 "cifMPI" , "h245.cifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_32" , HFILL }
 }
 , {
 & hf_h245_cif4MPI_1_32 , {
 "cif4MPI" , "h245.cif4MPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_32" , HFILL }
 }
 , {
 & hf_h245_cif16MPI_1_32 , {
 "cif16MPI" , "h245.cif16MPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_32" , HFILL }
 }
 , {
 & hf_h245_maxBitRate , {
 "maxBitRate" , "h245.maxBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_192400" , HFILL }
 }
 , {
 & hf_h245_unrestrictedVector , {
 "unrestrictedVector" , "h245.unrestrictedVector" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_arithmeticCoding , {
 "arithmeticCoding" , "h245.arithmeticCoding" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_advancedPrediction , {
 "advancedPrediction" , "h245.advancedPrediction" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_pbFrames , {
 "pbFrames" , "h245.pbFrames" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_hrd_B , {
 "hrd-B" , "h245.hrd_B" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_524287" , HFILL }
 }
 , {
 & hf_h245_bppMaxKb , {
 "bppMaxKb" , "h245.bppMaxKb" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_slowSqcifMPI , {
 "slowSqcifMPI" , "h245.slowSqcifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_3600" , HFILL }
 }
 , {
 & hf_h245_slowQcifMPI , {
 "slowQcifMPI" , "h245.slowQcifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_3600" , HFILL }
 }
 , {
 & hf_h245_slowCifMPI , {
 "slowCifMPI" , "h245.slowCifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_3600" , HFILL }
 }
 , {
 & hf_h245_slowCif4MPI , {
 "slowCif4MPI" , "h245.slowCif4MPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_3600" , HFILL }
 }
 , {
 & hf_h245_slowCif16MPI , {
 "slowCif16MPI" , "h245.slowCif16MPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_3600" , HFILL }
 }
 , {
 & hf_h245_errorCompensation , {
 "errorCompensation" , "h245.errorCompensation" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_enhancementLayerInfo , {
 "enhancementLayerInfo" , "h245.enhancementLayerInfo_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h263Options , {
 "h263Options" , "h245.h263Options_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_baseBitRateConstrained , {
 "baseBitRateConstrained" , "h245.baseBitRateConstrained" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_snrEnhancement , {
 "snrEnhancement" , "h245.snrEnhancement" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_14_OF_EnhancementOptions" , HFILL }
 }
 , {
 & hf_h245_snrEnhancement_item , {
 "EnhancementOptions" , "h245.EnhancementOptions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_spatialEnhancement , {
 "spatialEnhancement" , "h245.spatialEnhancement" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_14_OF_EnhancementOptions" , HFILL }
 }
 , {
 & hf_h245_spatialEnhancement_item , {
 "EnhancementOptions" , "h245.EnhancementOptions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_bPictureEnhancement , {
 "bPictureEnhancement" , "h245.bPictureEnhancement" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_14_OF_BEnhancementParameters" , HFILL }
 }
 , {
 & hf_h245_bPictureEnhancement_item , {
 "BEnhancementParameters" , "h245.BEnhancementParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_enhancementOptions , {
 "enhancementOptions" , "h245.enhancementOptions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_numberOfBPictures , {
 "numberOfBPictures" , "h245.numberOfBPictures" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_64" , HFILL }
 }
 , {
 & hf_h245_advancedIntraCodingMode , {
 "advancedIntraCodingMode" , "h245.advancedIntraCodingMode" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_deblockingFilterMode , {
 "deblockingFilterMode" , "h245.deblockingFilterMode" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_improvedPBFramesMode , {
 "improvedPBFramesMode" , "h245.improvedPBFramesMode" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_unlimitedMotionVectors , {
 "unlimitedMotionVectors" , "h245.unlimitedMotionVectors" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_fullPictureFreeze , {
 "fullPictureFreeze" , "h245.fullPictureFreeze" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_partialPictureFreezeAndRelease , {
 "partialPictureFreezeAndRelease" , "h245.partialPictureFreezeAndRelease" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_resizingPartPicFreezeAndRelease , {
 "resizingPartPicFreezeAndRelease" , "h245.resizingPartPicFreezeAndRelease" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_fullPictureSnapshot , {
 "fullPictureSnapshot" , "h245.fullPictureSnapshot" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_partialPictureSnapshot , {
 "partialPictureSnapshot" , "h245.partialPictureSnapshot" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoSegmentTagging , {
 "videoSegmentTagging" , "h245.videoSegmentTagging" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_progressiveRefinement , {
 "progressiveRefinement" , "h245.progressiveRefinement" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dynamicPictureResizingByFour , {
 "dynamicPictureResizingByFour" , "h245.dynamicPictureResizingByFour" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dynamicPictureResizingSixteenthPel , {
 "dynamicPictureResizingSixteenthPel" , "h245.dynamicPictureResizingSixteenthPel" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dynamicWarpingHalfPel , {
 "dynamicWarpingHalfPel" , "h245.dynamicWarpingHalfPel" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dynamicWarpingSixteenthPel , {
 "dynamicWarpingSixteenthPel" , "h245.dynamicWarpingSixteenthPel" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_independentSegmentDecoding , {
 "independentSegmentDecoding" , "h245.independentSegmentDecoding" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_slicesInOrder_NonRect , {
 "slicesInOrder-NonRect" , "h245.slicesInOrder_NonRect" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_slicesInOrder_Rect , {
 "slicesInOrder-Rect" , "h245.slicesInOrder_Rect" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_slicesNoOrder_NonRect , {
 "slicesNoOrder-NonRect" , "h245.slicesNoOrder_NonRect" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_slicesNoOrder_Rect , {
 "slicesNoOrder-Rect" , "h245.slicesNoOrder_Rect" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_alternateInterVLCMode , {
 "alternateInterVLCMode" , "h245.alternateInterVLCMode" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_modifiedQuantizationMode , {
 "modifiedQuantizationMode" , "h245.modifiedQuantizationMode" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_reducedResolutionUpdate , {
 "reducedResolutionUpdate" , "h245.reducedResolutionUpdate" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_transparencyParameters , {
 "transparencyParameters" , "h245.transparencyParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_separateVideoBackChannel , {
 "separateVideoBackChannel" , "h245.separateVideoBackChannel" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_refPictureSelection , {
 "refPictureSelection" , "h245.refPictureSelection_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_customPictureClockFrequency , {
 "customPictureClockFrequency" , "h245.customPictureClockFrequency" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_16_OF_CustomPictureClockFrequency" , HFILL }
 }
 , {
 & hf_h245_customPictureClockFrequency_item , {
 "CustomPictureClockFrequency" , "h245.CustomPictureClockFrequency_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_customPictureFormat , {
 "customPictureFormat" , "h245.customPictureFormat" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_16_OF_CustomPictureFormat" , HFILL }
 }
 , {
 & hf_h245_customPictureFormat_item , {
 "CustomPictureFormat" , "h245.CustomPictureFormat_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_modeCombos , {
 "modeCombos" , "h245.modeCombos" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_16_OF_H263VideoModeCombos" , HFILL }
 }
 , {
 & hf_h245_modeCombos_item , {
 "H263VideoModeCombos" , "h245.H263VideoModeCombos_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h263Version3Options , {
 "h263Version3Options" , "h245.h263Version3Options_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_presentationOrder , {
 "presentationOrder" , "h245.presentationOrder" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_offset_x , {
 "offset-x" , "h245.offset_x" , FT_INT32 , BASE_DEC , NULL , 0 , "INTEGER_M262144_262143" , HFILL }
 }
 , {
 & hf_h245_offset_y , {
 "offset-y" , "h245.offset_y" , FT_INT32 , BASE_DEC , NULL , 0 , "INTEGER_M262144_262143" , HFILL }
 }
 , {
 & hf_h245_scale_x , {
 "scale-x" , "h245.scale_x" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_scale_y , {
 "scale-y" , "h245.scale_y" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_additionalPictureMemory , {
 "additionalPictureMemory" , "h245.additionalPictureMemory_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sqcifAdditionalPictureMemory , {
 "sqcifAdditionalPictureMemory" , "h245.sqcifAdditionalPictureMemory" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_qcifAdditionalPictureMemory , {
 "qcifAdditionalPictureMemory" , "h245.qcifAdditionalPictureMemory" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_cifAdditionalPictureMemory , {
 "cifAdditionalPictureMemory" , "h245.cifAdditionalPictureMemory" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_cif4AdditionalPictureMemory , {
 "cif4AdditionalPictureMemory" , "h245.cif4AdditionalPictureMemory" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_cif16AdditionalPictureMemory , {
 "cif16AdditionalPictureMemory" , "h245.cif16AdditionalPictureMemory" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_bigCpfAdditionalPictureMemory , {
 "bigCpfAdditionalPictureMemory" , "h245.bigCpfAdditionalPictureMemory" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_videoMux , {
 "videoMux" , "h245.videoMux" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoBackChannelSend , {
 "videoBackChannelSend" , "h245.videoBackChannelSend" , FT_UINT32 , BASE_DEC , VALS ( h245_T_videoBackChannelSend_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_none , {
 "none" , "h245.none_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_ackMessageOnly , {
 "ackMessageOnly" , "h245.ackMessageOnly_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_nackMessageOnly , {
 "nackMessageOnly" , "h245.nackMessageOnly_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_ackOrNackMessageOnly , {
 "ackOrNackMessageOnly" , "h245.ackOrNackMessageOnly_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_ackAndNackMessage , {
 "ackAndNackMessage" , "h245.ackAndNackMessage_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_enhancedReferencePicSelect , {
 "enhancedReferencePicSelect" , "h245.enhancedReferencePicSelect_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_subPictureRemovalParameters , {
 "subPictureRemovalParameters" , "h245.subPictureRemovalParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mpuHorizMBs , {
 "mpuHorizMBs" , "h245.mpuHorizMBs" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_128" , HFILL }
 }
 , {
 & hf_h245_mpuVertMBs , {
 "mpuVertMBs" , "h245.mpuVertMBs" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_72" , HFILL }
 }
 , {
 & hf_h245_mpuTotalNumber , {
 "mpuTotalNumber" , "h245.mpuTotalNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65536" , HFILL }
 }
 , {
 & hf_h245_clockConversionCode , {
 "clockConversionCode" , "h245.clockConversionCode" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1000_1001" , HFILL }
 }
 , {
 & hf_h245_clockDivisor , {
 "clockDivisor" , "h245.clockDivisor" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_127" , HFILL }
 }
 , {
 & hf_h245_sqcifMPI , {
 "sqcifMPI" , "h245.sqcifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_qcifMPI_1_2048 , {
 "qcifMPI" , "h245.qcifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_cifMPI2_1_2048 , {
 "cifMPI" , "h245.cifMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_cif4MPI , {
 "cif4MPI" , "h245.cif4MPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_cif16MPI , {
 "cif16MPI" , "h245.cif16MPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_maxCustomPictureWidth , {
 "maxCustomPictureWidth" , "h245.maxCustomPictureWidth" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_maxCustomPictureHeight , {
 "maxCustomPictureHeight" , "h245.maxCustomPictureHeight" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_minCustomPictureWidth , {
 "minCustomPictureWidth" , "h245.minCustomPictureWidth" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_minCustomPictureHeight , {
 "minCustomPictureHeight" , "h245.minCustomPictureHeight" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_mPI , {
 "mPI" , "h245.mPI_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_standardMPI , {
 "standardMPI" , "h245.standardMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_31" , HFILL }
 }
 , {
 & hf_h245_customPCF , {
 "customPCF" , "h245.customPCF" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_customPCF_item , {
 "customPCF item" , "h245.customPCF_item_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_customMPI , {
 "customMPI" , "h245.customMPI" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_2048" , HFILL }
 }
 , {
 & hf_h245_pixelAspectInformation , {
 "pixelAspectInformation" , "h245.pixelAspectInformation" , FT_UINT32 , BASE_DEC , VALS ( h245_T_pixelAspectInformation_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_anyPixelAspectRatio , {
 "anyPixelAspectRatio" , "h245.anyPixelAspectRatio" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_pixelAspectCode , {
 "pixelAspectCode" , "h245.pixelAspectCode" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_pixelAspectCode_item , {
 "pixelAspectCode item" , "h245.pixelAspectCode_item" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_14" , HFILL }
 }
 , {
 & hf_h245_extendedPAR , {
 "extendedPAR" , "h245.extendedPAR" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_extendedPAR_item , {
 "extendedPAR item" , "h245.extendedPAR_item_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_width , {
 "width" , "h245.width" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_height , {
 "height" , "h245.height" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_h263VideoUncoupledModes , {
 "h263VideoUncoupledModes" , "h245.h263VideoUncoupledModes_element" , FT_NONE , BASE_NONE , NULL , 0 , "H263ModeComboFlags" , HFILL }
 }
 , {
 & hf_h245_h263VideoCoupledModes , {
 "h263VideoCoupledModes" , "h245.h263VideoCoupledModes" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_16_OF_H263ModeComboFlags" , HFILL }
 }
 , {
 & hf_h245_h263VideoCoupledModes_item , {
 "H263ModeComboFlags" , "h245.H263ModeComboFlags_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_referencePicSelect , {
 "referencePicSelect" , "h245.referencePicSelect" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_enhancedReferencePicSelectBool , {
 "enhancedReferencePicSelect" , "h245.enhancedReferencePicSelect" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_dataPartitionedSlices , {
 "dataPartitionedSlices" , "h245.dataPartitionedSlices" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_fixedPointIDCT0 , {
 "fixedPointIDCT0" , "h245.fixedPointIDCT0" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_interlacedFields , {
 "interlacedFields" , "h245.interlacedFields" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_currentPictureHeaderRepetition , {
 "currentPictureHeaderRepetition" , "h245.currentPictureHeaderRepetition" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_previousPictureHeaderRepetition , {
 "previousPictureHeaderRepetition" , "h245.previousPictureHeaderRepetition" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_nextPictureHeaderRepetition , {
 "nextPictureHeaderRepetition" , "h245.nextPictureHeaderRepetition" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_pictureNumberBoolean , {
 "pictureNumber" , "h245.pictureNumber" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_spareReferencePictures , {
 "spareReferencePictures" , "h245.spareReferencePictures" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_constrainedBitstream , {
 "constrainedBitstream" , "h245.constrainedBitstream" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_pictureRate , {
 "pictureRate" , "h245.pictureRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_15" , HFILL }
 }
 , {
 & hf_h245_g711Alaw64k , {
 "g711Alaw64k" , "h245.g711Alaw64k" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g711Alaw56k , {
 "g711Alaw56k" , "h245.g711Alaw56k" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g711Ulaw64k , {
 "g711Ulaw64k" , "h245.g711Ulaw64k" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g711Ulaw56k , {
 "g711Ulaw56k" , "h245.g711Ulaw56k" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g722_64k , {
 "g722-64k" , "h245.g722_64k" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g722_56k , {
 "g722-56k" , "h245.g722_56k" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g722_48k , {
 "g722-48k" , "h245.g722_48k" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g7231 , {
 "g7231" , "h245.g7231_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maxAl_sduAudioFrames , {
 "maxAl-sduAudioFrames" , "h245.maxAl_sduAudioFrames" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_silenceSuppression , {
 "silenceSuppression" , "h245.silenceSuppression" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_g728 , {
 "g728" , "h245.g728" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g729 , {
 "g729" , "h245.g729" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g729AnnexA , {
 "g729AnnexA" , "h245.g729AnnexA" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_is11172AudioCapability , {
 "is11172AudioCapability" , "h245.is11172AudioCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_is13818AudioCapability , {
 "is13818AudioCapability" , "h245.is13818AudioCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g729wAnnexB , {
 "g729wAnnexB" , "h245.g729wAnnexB" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g729AnnexAwAnnexB , {
 "g729AnnexAwAnnexB" , "h245.g729AnnexAwAnnexB" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_g7231AnnexCCapability , {
 "g7231AnnexCCapability" , "h245.g7231AnnexCCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_gsmFullRate , {
 "gsmFullRate" , "h245.gsmFullRate_element" , FT_NONE , BASE_NONE , NULL , 0 , "GSMAudioCapability" , HFILL }
 }
 , {
 & hf_h245_gsmHalfRate , {
 "gsmHalfRate" , "h245.gsmHalfRate_element" , FT_NONE , BASE_NONE , NULL , 0 , "GSMAudioCapability" , HFILL }
 }
 , {
 & hf_h245_gsmEnhancedFullRate , {
 "gsmEnhancedFullRate" , "h245.gsmEnhancedFullRate_element" , FT_NONE , BASE_NONE , NULL , 0 , "GSMAudioCapability" , HFILL }
 }
 , {
 & hf_h245_genericAudioCapability , {
 "genericAudioCapability" , "h245.genericAudioCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_g729Extensions , {
 "g729Extensions" , "h245.g729Extensions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_vbd , {
 "vbd" , "h245.vbd_element" , FT_NONE , BASE_NONE , NULL , 0 , "VBDCapability" , HFILL }
 }
 , {
 & hf_h245_audioTelephonyEvent , {
 "audioTelephonyEvent" , "h245.audioTelephonyEvent_element" , FT_NONE , BASE_NONE , NULL , 0 , "NoPTAudioTelephonyEventCapability" , HFILL }
 }
 , {
 & hf_h245_audioTone , {
 "audioTone" , "h245.audioTone_element" , FT_NONE , BASE_NONE , NULL , 0 , "NoPTAudioToneCapability" , HFILL }
 }
 , {
 & hf_h245_audioUnit , {
 "audioUnit" , "h245.audioUnit" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_annexA , {
 "annexA" , "h245.annexA" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_annexB , {
 "annexB" , "h245.annexB" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_annexD , {
 "annexD" , "h245.annexD" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_annexE , {
 "annexE" , "h245.annexE" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_annexF , {
 "annexF" , "h245.annexF" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_annexG , {
 "annexG" , "h245.annexG" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_annexH , {
 "annexH" , "h245.annexH" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_highRateMode0 , {
 "highRateMode0" , "h245.highRateMode0" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_27_78" , HFILL }
 }
 , {
 & hf_h245_highRateMode1 , {
 "highRateMode1" , "h245.highRateMode1" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_27_78" , HFILL }
 }
 , {
 & hf_h245_lowRateMode0 , {
 "lowRateMode0" , "h245.lowRateMode0" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_23_66" , HFILL }
 }
 , {
 & hf_h245_lowRateMode1 , {
 "lowRateMode1" , "h245.lowRateMode1" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_23_66" , HFILL }
 }
 , {
 & hf_h245_sidMode0 , {
 "sidMode0" , "h245.sidMode0" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_6_17" , HFILL }
 }
 , {
 & hf_h245_sidMode1 , {
 "sidMode1" , "h245.sidMode1" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_6_17" , HFILL }
 }
 , {
 & hf_h245_g723AnnexCAudioMode , {
 "g723AnnexCAudioMode" , "h245.g723AnnexCAudioMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioLayer1 , {
 "audioLayer1" , "h245.audioLayer1" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioLayer2 , {
 "audioLayer2" , "h245.audioLayer2" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioLayer3 , {
 "audioLayer3" , "h245.audioLayer3" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioSampling32k , {
 "audioSampling32k" , "h245.audioSampling32k" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioSampling44k1 , {
 "audioSampling44k1" , "h245.audioSampling44k1" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioSampling48k , {
 "audioSampling48k" , "h245.audioSampling48k" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_singleChannel , {
 "singleChannel" , "h245.singleChannel" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_twoChannels , {
 "twoChannels" , "h245.twoChannels" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_bitRate_1_448 , {
 "bitRate" , "h245.bitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_448" , HFILL }
 }
 , {
 & hf_h245_audioSampling16k , {
 "audioSampling16k" , "h245.audioSampling16k" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioSampling22k05 , {
 "audioSampling22k05" , "h245.audioSampling22k05" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_audioSampling24k , {
 "audioSampling24k" , "h245.audioSampling24k" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_threeChannels2_1 , {
 "threeChannels2-1" , "h245.threeChannels2_1" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_threeChannels3_0 , {
 "threeChannels3-0" , "h245.threeChannels3_0" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_fourChannels2_0_2_0 , {
 "fourChannels2-0-2-0" , "h245.fourChannels2_0_2_0" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_fourChannels2_2 , {
 "fourChannels2-2" , "h245.fourChannels2_2" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_fourChannels3_1 , {
 "fourChannels3-1" , "h245.fourChannels3_1" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_fiveChannels3_0_2_0 , {
 "fiveChannels3-0-2-0" , "h245.fiveChannels3_0_2_0" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_fiveChannels3_2 , {
 "fiveChannels3-2" , "h245.fiveChannels3_2" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_lowFrequencyEnhancement , {
 "lowFrequencyEnhancement" , "h245.lowFrequencyEnhancement" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_multilingual , {
 "multilingual" , "h245.multilingual" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_bitRate2_1_1130 , {
 "bitRate" , "h245.bitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_1130" , HFILL }
 }
 , {
 & hf_h245_audioUnitSize , {
 "audioUnitSize" , "h245.audioUnitSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_comfortNoise , {
 "comfortNoise" , "h245.comfortNoise" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_scrambled , {
 "scrambled" , "h245.scrambled" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_vbd_cap_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_AudioCapability_vals ) , 0 , "AudioCapability" , HFILL }
 }
 , {
 & hf_h245_t120 , {
 "t120" , "h245.t120" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_dsm_cc , {
 "dsm-cc" , "h245.dsm_cc" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_userData , {
 "userData" , "h245.userData" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_t84 , {
 "t84" , "h245.t84_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t84Protocol , {
 "t84Protocol" , "h245.t84Protocol" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_t84Profile , {
 "t84Profile" , "h245.t84Profile" , FT_UINT32 , BASE_DEC , VALS ( h245_T84Profile_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t434 , {
 "t434" , "h245.t434" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_h224 , {
 "h224" , "h245.h224" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_nlpidProtocol , {
 "nlpidProtocol" , "h245.nlpidProtocol" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_nlpidData , {
 "nlpidData" , "h245.nlpidData" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING" , HFILL }
 }
 , {
 & hf_h245_nlpid , {
 "nlpid" , "h245.nlpid_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dsvdControl , {
 "dsvdControl" , "h245.dsvdControl_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h222DataPartitioning , {
 "h222DataPartitioning" , "h245.h222DataPartitioning" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_t30fax , {
 "t30fax" , "h245.t30fax" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_t140 , {
 "t140" , "h245.t140" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_t38fax , {
 "t38fax" , "h245.t38fax_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t38FaxProtocol , {
 "t38FaxProtocol" , "h245.t38FaxProtocol" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_t38FaxProfile , {
 "t38FaxProfile" , "h245.t38FaxProfile_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericDataCapability , {
 "genericDataCapability" , "h245.genericDataCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_application , {
 "application" , "h245.application" , FT_UINT32 , BASE_DEC , VALS ( h245_Application_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maxBitRate2_0_4294967295 , {
 "maxBitRate" , "h245.maxBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4294967295" , HFILL }
 }
 , {
 & hf_h245_v14buffered , {
 "v14buffered" , "h245.v14buffered_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v42lapm , {
 "v42lapm" , "h245.v42lapm_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_hdlcFrameTunnelling , {
 "hdlcFrameTunnelling" , "h245.hdlcFrameTunnelling_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h310SeparateVCStack , {
 "h310SeparateVCStack" , "h245.h310SeparateVCStack_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h310SingleVCStack , {
 "h310SingleVCStack" , "h245.h310SingleVCStack_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_transparent , {
 "transparent" , "h245.transparent_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_segmentationAndReassembly , {
 "segmentationAndReassembly" , "h245.segmentationAndReassembly_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_hdlcFrameTunnelingwSAR , {
 "hdlcFrameTunnelingwSAR" , "h245.hdlcFrameTunnelingwSAR_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v120 , {
 "v120" , "h245.v120_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_separateLANStack , {
 "separateLANStack" , "h245.separateLANStack_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v76wCompression , {
 "v76wCompression" , "h245.v76wCompression" , FT_UINT32 , BASE_DEC , VALS ( h245_T_v76wCompression_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_transmitCompression , {
 "transmitCompression" , "h245.transmitCompression" , FT_UINT32 , BASE_DEC , VALS ( h245_CompressionType_vals ) , 0 , "CompressionType" , HFILL }
 }
 , {
 & hf_h245_receiveCompression , {
 "receiveCompression" , "h245.receiveCompression" , FT_UINT32 , BASE_DEC , VALS ( h245_CompressionType_vals ) , 0 , "CompressionType" , HFILL }
 }
 , {
 & hf_h245_transmitAndReceiveCompression , {
 "transmitAndReceiveCompression" , "h245.transmitAndReceiveCompression" , FT_UINT32 , BASE_DEC , VALS ( h245_CompressionType_vals ) , 0 , "CompressionType" , HFILL }
 }
 , {
 & hf_h245_tcp , {
 "tcp" , "h245.tcp_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_udp , {
 "udp" , "h245.udp_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v42bis , {
 "v42bis" , "h245.v42bis_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_numberOfCodewords , {
 "numberOfCodewords" , "h245.numberOfCodewords" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65536" , HFILL }
 }
 , {
 & hf_h245_maximumStringLength , {
 "maximumStringLength" , "h245.maximumStringLength" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_256" , HFILL }
 }
 , {
 & hf_h245_t84Unrestricted , {
 "t84Unrestricted" , "h245.t84Unrestricted_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t84Restricted , {
 "t84Restricted" , "h245.t84Restricted_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_qcif_bool , {
 "qcif" , "h245.qcif" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_cif_bool , {
 "cif" , "h245.cif" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_ccir601Seq , {
 "ccir601Seq" , "h245.ccir601Seq" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_ccir601Prog , {
 "ccir601Prog" , "h245.ccir601Prog" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_hdtvSeq , {
 "hdtvSeq" , "h245.hdtvSeq" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_hdtvProg , {
 "hdtvProg" , "h245.hdtvProg" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_g3FacsMH200x100 , {
 "g3FacsMH200x100" , "h245.g3FacsMH200x100" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_g3FacsMH200x200 , {
 "g3FacsMH200x200" , "h245.g3FacsMH200x200" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_g4FacsMMR200x100 , {
 "g4FacsMMR200x100" , "h245.g4FacsMMR200x100" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_g4FacsMMR200x200 , {
 "g4FacsMMR200x200" , "h245.g4FacsMMR200x200" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_jbig200x200Seq , {
 "jbig200x200Seq" , "h245.jbig200x200Seq" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_jbig200x200Prog , {
 "jbig200x200Prog" , "h245.jbig200x200Prog" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_jbig300x300Seq , {
 "jbig300x300Seq" , "h245.jbig300x300Seq" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_jbig300x300Prog , {
 "jbig300x300Prog" , "h245.jbig300x300Prog" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_digPhotoLow , {
 "digPhotoLow" , "h245.digPhotoLow" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_digPhotoMedSeq , {
 "digPhotoMedSeq" , "h245.digPhotoMedSeq" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_digPhotoMedProg , {
 "digPhotoMedProg" , "h245.digPhotoMedProg" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_digPhotoHighSeq , {
 "digPhotoHighSeq" , "h245.digPhotoHighSeq" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_digPhotoHighProg , {
 "digPhotoHighProg" , "h245.digPhotoHighProg" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_fillBitRemoval , {
 "fillBitRemoval" , "h245.fillBitRemoval" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_transcodingJBIG , {
 "transcodingJBIG" , "h245.transcodingJBIG" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_transcodingMMR , {
 "transcodingMMR" , "h245.transcodingMMR" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_version , {
 "version" , "h245.version" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_t38FaxRateManagement , {
 "t38FaxRateManagement" , "h245.t38FaxRateManagement" , FT_UINT32 , BASE_DEC , VALS ( h245_T38FaxRateManagement_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t38FaxUdpOptions , {
 "t38FaxUdpOptions" , "h245.t38FaxUdpOptions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t38FaxTcpOptions , {
 "t38FaxTcpOptions" , "h245.t38FaxTcpOptions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_localTCF , {
 "localTCF" , "h245.localTCF_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_transferredTCF , {
 "transferredTCF" , "h245.transferredTCF_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t38FaxMaxBuffer , {
 "t38FaxMaxBuffer" , "h245.t38FaxMaxBuffer" , FT_INT32 , BASE_DEC , NULL , 0 , "INTEGER" , HFILL }
 }
 , {
 & hf_h245_t38FaxMaxDatagram , {
 "t38FaxMaxDatagram" , "h245.t38FaxMaxDatagram" , FT_INT32 , BASE_DEC , NULL , 0 , "INTEGER" , HFILL }
 }
 , {
 & hf_h245_t38FaxUdpEC , {
 "t38FaxUdpEC" , "h245.t38FaxUdpEC" , FT_UINT32 , BASE_DEC , VALS ( h245_T_t38FaxUdpEC_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t38UDPFEC , {
 "t38UDPFEC" , "h245.t38UDPFEC_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t38UDPRedundancy , {
 "t38UDPRedundancy" , "h245.t38UDPRedundancy_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_t38TCPBidirectionalMode , {
 "t38TCPBidirectionalMode" , "h245.t38TCPBidirectionalMode" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_encryptionCapability , {
 "encryptionCapability" , "h245.encryptionCapability" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_authenticationCapability , {
 "authenticationCapability" , "h245.authenticationCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_integrityCapability , {
 "integrityCapability" , "h245.integrityCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericH235SecurityCapability , {
 "genericH235SecurityCapability" , "h245.genericH235SecurityCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_EncryptionCapability_item , {
 "MediaEncryptionAlgorithm" , "h245.MediaEncryptionAlgorithm" , FT_UINT32 , BASE_DEC , VALS ( h245_MediaEncryptionAlgorithm_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_algorithm , {
 "algorithm" , "h245.algorithm" , FT_OID , BASE_NONE , NULL , 0 , "OBJECT_IDENTIFIER" , HFILL }
 }
 , {
 & hf_h245_antiSpamAlgorithm , {
 "antiSpamAlgorithm" , "h245.antiSpamAlgorithm" , FT_OID , BASE_NONE , NULL , 0 , "OBJECT_IDENTIFIER" , HFILL }
 }
 , {
 & hf_h245_ui_nonStandard , {
 "nonStandard" , "h245.nonStandard" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_SIZE_1_16_OF_NonStandardParameter" , HFILL }
 }
 , {
 & hf_h245_ui_nonStandard_item , {
 "NonStandardParameter" , "h245.NonStandardParameter_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_basicString , {
 "basicString" , "h245.basicString_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_iA5String , {
 "iA5String" , "h245.iA5String_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_generalString , {
 "generalString" , "h245.generalString_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dtmf , {
 "dtmf" , "h245.dtmf_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_hookflash , {
 "hookflash" , "h245.hookflash_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_extendedAlphanumericFlag , {
 "extendedAlphanumeric" , "h245.extendedAlphanumeric_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptedBasicString , {
 "encryptedBasicString" , "h245.encryptedBasicString_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptedIA5String , {
 "encryptedIA5String" , "h245.encryptedIA5String_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptedGeneralString , {
 "encryptedGeneralString" , "h245.encryptedGeneralString_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_secureDTMF , {
 "secureDTMF" , "h245.secureDTMF_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericUserInputCapability , {
 "genericUserInputCapability" , "h245.genericUserInputCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_nonStandardParams , {
 "nonStandardData" , "h245.nonStandardData" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_NonStandardParameter" , HFILL }
 }
 , {
 & hf_h245_nonStandardParams_item , {
 "NonStandardParameter" , "h245.NonStandardParameter_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_chairControlCapability , {
 "chairControlCapability" , "h245.chairControlCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_videoIndicateMixingCapability , {
 "videoIndicateMixingCapability" , "h245.videoIndicateMixingCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_multipointVisualizationCapability , {
 "multipointVisualizationCapability" , "h245.multipointVisualizationCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_capabilityIdentifier , {
 "capabilityIdentifier" , "h245.capabilityIdentifier" , FT_UINT32 , BASE_DEC , VALS ( h245_CapabilityIdentifier_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_collapsing , {
 "collapsing" , "h245.collapsing" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_collapsing_item , {
 "collapsing item" , "h245.collapsing_item_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_nonCollapsing , {
 "nonCollapsing" , "h245.nonCollapsing" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_nonCollapsing_item , {
 "nonCollapsing item" , "h245.nonCollapsing_item_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_nonCollapsingRaw , {
 "nonCollapsingRaw" , "h245.nonCollapsingRaw" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_transport , {
 "transport" , "h245.transport" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_standardOid , {
 "standard" , "h245.standard" , FT_OID , BASE_NONE , NULL , 0 , "T_standardOid" , HFILL }
 }
 , {
 & hf_h245_h221NonStandard , {
 "h221NonStandard" , "h245.h221NonStandard_element" , FT_NONE , BASE_NONE , NULL , 0 , "NonStandardParameter" , HFILL }
 }
 , {
 & hf_h245_uuid , {
 "uuid" , "h245.uuid" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_16" , HFILL }
 }
 , {
 & hf_h245_domainBased , {
 "domainBased" , "h245.domainBased" , FT_STRING , BASE_NONE , NULL , 0 , "IA5String_SIZE_1_64" , HFILL }
 }
 , {
 & hf_h245_parameterIdentifier , {
 "parameterIdentifier" , "h245.parameterIdentifier" , FT_UINT32 , BASE_DEC , VALS ( h245_ParameterIdentifier_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_parameterValue , {
 "parameterValue" , "h245.parameterValue" , FT_UINT32 , BASE_DEC , VALS ( h245_ParameterValue_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_supersedes , {
 "supersedes" , "h245.supersedes" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_ParameterIdentifier" , HFILL }
 }
 , {
 & hf_h245_supersedes_item , {
 "ParameterIdentifier" , "h245.ParameterIdentifier" , FT_UINT32 , BASE_DEC , VALS ( h245_ParameterIdentifier_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_standard , {
 "standard" , "h245.standard" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_logical , {
 "logical" , "h245.logical_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_booleanArray , {
 "booleanArray" , "h245.booleanArray" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_unsignedMin , {
 "unsignedMin" , "h245.unsignedMin" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_unsignedMax , {
 "unsignedMax" , "h245.unsignedMax" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_unsigned32Min , {
 "unsigned32Min" , "h245.unsigned32Min" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_unsigned32Max , {
 "unsigned32Max" , "h245.unsigned32Max" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_octetString , {
 "octetString" , "h245.octetString" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericParameters , {
 "genericParameter" , "h245.genericParameter" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_GenericParameter" , HFILL }
 }
 , {
 & hf_h245_genericParameters_item , {
 "GenericParameter" , "h245.GenericParameter_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexFormat , {
 "multiplexFormat" , "h245.multiplexFormat" , FT_UINT32 , BASE_DEC , VALS ( h245_MultiplexFormat_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_controlOnMuxStream , {
 "controlOnMuxStream" , "h245.controlOnMuxStream" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_capabilityOnMuxStream , {
 "capabilityOnMuxStream" , "h245.capabilityOnMuxStream" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_256_OF_AlternativeCapabilitySet" , HFILL }
 }
 , {
 & hf_h245_capabilityOnMuxStream_item , {
 "AlternativeCapabilitySet" , "h245.AlternativeCapabilitySet" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dynamicRTPPayloadType , {
 "dynamicRTPPayloadType" , "h245.dynamicRTPPayloadType" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_96_127" , HFILL }
 }
 , {
 & hf_h245_audioTelephoneEvent , {
 "audioTelephoneEvent" , "h245.audioTelephoneEvent" , FT_STRING , BASE_NONE , NULL , 0 , "GeneralString" , HFILL }
 }
 , {
 & hf_h245_capabilities , {
 "capabilities" , "h245.capabilities" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_256_OF_AlternativeCapabilitySet" , HFILL }
 }
 , {
 & hf_h245_capabilities_item , {
 "AlternativeCapabilitySet" , "h245.AlternativeCapabilitySet" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fecc_rfc2733 , {
 "rfc2733" , "h245.rfc2733_element" , FT_NONE , BASE_NONE , NULL , 0 , "FECC_rfc2733" , HFILL }
 }
 , {
 & hf_h245_redundancyEncodingBool , {
 "redundancyEncoding" , "h245.redundancyEncoding" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_separateStreamBool , {
 "separateStream" , "h245.separateStream_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_separateStreamBool" , HFILL }
 }
 , {
 & hf_h245_separatePort , {
 "separatePort" , "h245.separatePort" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_samePortBool , {
 "samePort" , "h245.samePort" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_protectedCapability , {
 "protectedCapability" , "h245.protectedCapability" , FT_UINT32 , BASE_DEC , NULL , 0 , "CapabilityTableEntryNumber" , HFILL }
 }
 , {
 & hf_h245_fecScheme , {
 "fecScheme" , "h245.fecScheme" , FT_OID , BASE_NONE , NULL , 0 , "OBJECT_IDENTIFIER" , HFILL }
 }
 , {
 & hf_h245_rfc2733rfc2198 , {
 "rfc2733rfc2198" , "h245.rfc2733rfc2198" , FT_UINT32 , BASE_DEC , NULL , 0 , "MaxRedundancy" , HFILL }
 }
 , {
 & hf_h245_rfc2733sameport , {
 "rfc2733sameport" , "h245.rfc2733sameport" , FT_UINT32 , BASE_DEC , NULL , 0 , "MaxRedundancy" , HFILL }
 }
 , {
 & hf_h245_rfc2733diffport , {
 "rfc2733diffport" , "h245.rfc2733diffport" , FT_UINT32 , BASE_DEC , NULL , 0 , "MaxRedundancy" , HFILL }
 }
 , {
 & hf_h245_rfc2733Format , {
 "rfc2733Format" , "h245.rfc2733Format" , FT_UINT32 , BASE_DEC , VALS ( h245_Rfc2733Format_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_olc_fw_lcn , {
 "forwardLogicalChannelNumber" , "h245.forwardLogicalChannelNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "OLC_fw_lcn" , HFILL }
 }
 , {
 & hf_h245_forwardLogicalChannelParameters , {
 "forwardLogicalChannelParameters" , "h245.forwardLogicalChannelParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_portNumber , {
 "portNumber" , "h245.portNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_dataType , {
 "dataType" , "h245.dataType" , FT_UINT32 , BASE_DEC , VALS ( h245_DataType_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_olc_forw_multiplexParameters , {
 "multiplexParameters" , "h245.multiplexParameters" , FT_UINT32 , BASE_DEC , VALS ( h245_OLC_forw_multiplexParameters_vals ) , 0 , "OLC_forw_multiplexParameters" , HFILL }
 }
 , {
 & hf_h245_h222LogicalChannelParameters , {
 "h222LogicalChannelParameters" , "h245.h222LogicalChannelParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_olc_fw_h223_params , {
 "h223LogicalChannelParameters" , "h245.h223LogicalChannelParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , "OLC_fw_h223_params" , HFILL }
 }
 , {
 & hf_h245_v76LogicalChannelParameters , {
 "v76LogicalChannelParameters" , "h245.v76LogicalChannelParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h2250LogicalChannelParameters , {
 "h2250LogicalChannelParameters" , "h245.h2250LogicalChannelParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_forwardLogicalChannelDependency , {
 "forwardLogicalChannelDependency" , "h245.forwardLogicalChannelDependency" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_replacementFor , {
 "replacementFor" , "h245.replacementFor" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_reverseLogicalChannelParameters , {
 "reverseLogicalChannelParameters" , "h245.reverseLogicalChannelParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , "OLC_reverseLogicalChannelParameters" , HFILL }
 }
 , {
 & hf_h245_olc_rev_multiplexParameter , {
 "multiplexParameters" , "h245.multiplexParameters" , FT_UINT32 , BASE_DEC , VALS ( h245_OLC_rev_multiplexParameters_vals ) , 0 , "OLC_rev_multiplexParameters" , HFILL }
 }
 , {
 & hf_h245_olc_rev_h223_params , {
 "h223LogicalChannelParameters" , "h245.h223LogicalChannelParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , "OLC_rev_h223_params" , HFILL }
 }
 , {
 & hf_h245_reverseLogicalChannelDependency , {
 "reverseLogicalChannelDependency" , "h245.reverseLogicalChannelDependency" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_separateStack , {
 "separateStack" , "h245.separateStack_element" , FT_NONE , BASE_NONE , NULL , 0 , "NetworkAccessParameters" , HFILL }
 }
 , {
 & hf_h245_encryptionSync , {
 "encryptionSync" , "h245.encryptionSync_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_distribution , {
 "distribution" , "h245.distribution" , FT_UINT32 , BASE_DEC , VALS ( h245_T_distribution_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_unicast , {
 "unicast" , "h245.unicast_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multicast , {
 "multicast" , "h245.multicast_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_networkAddress , {
 "networkAddress" , "h245.networkAddress" , FT_UINT32 , BASE_DEC , VALS ( h245_T_networkAddress_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_q2931Address , {
 "q2931Address" , "h245.q2931Address_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_e164Address , {
 "e164Address" , "h245.e164Address" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_localAreaAddress , {
 "localAreaAddress" , "h245.localAreaAddress" , FT_UINT32 , BASE_DEC , VALS ( h245_TransportAddress_vals ) , 0 , "TransportAddress" , HFILL }
 }
 , {
 & hf_h245_associateConference , {
 "associateConference" , "h245.associateConference" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_externalReference , {
 "externalReference" , "h245.externalReference" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1_255" , HFILL }
 }
 , {
 & hf_h245_t120SetupProcedure , {
 "t120SetupProcedure" , "h245.t120SetupProcedure" , FT_UINT32 , BASE_DEC , VALS ( h245_T_t120SetupProcedure_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_originateCall , {
 "originateCall" , "h245.originateCall_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_waitForCall , {
 "waitForCall" , "h245.waitForCall_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_issueQuery , {
 "issueQuery" , "h245.issueQuery_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_address , {
 "address" , "h245.address" , FT_UINT32 , BASE_DEC , VALS ( h245_T_address_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_internationalNumber , {
 "internationalNumber" , "h245.internationalNumber" , FT_STRING , BASE_NONE , NULL , 0 , "NumericString_SIZE_1_16" , HFILL }
 }
 , {
 & hf_h245_nsapAddress , {
 "nsapAddress" , "h245.nsapAddress" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1_20" , HFILL }
 }
 , {
 & hf_h245_subaddress , {
 "subaddress" , "h245.subaddress" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1_20" , HFILL }
 }
 , {
 & hf_h245_audioHeaderPresent , {
 "audioHeaderPresent" , "h245.audioHeaderPresent" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_nullData , {
 "nullData" , "h245.nullData_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoData , {
 "videoData" , "h245.videoData" , FT_UINT32 , BASE_DEC , VALS ( h245_VideoCapability_vals ) , 0 , "VideoCapability" , HFILL }
 }
 , {
 & hf_h245_audioData , {
 "audioData" , "h245.audioData" , FT_UINT32 , BASE_DEC , VALS ( h245_AudioCapability_vals ) , 0 , "AudioCapability" , HFILL }
 }
 , {
 & hf_h245_data , {
 "data" , "h245.data_element" , FT_NONE , BASE_NONE , NULL , 0 , "DataApplicationCapability" , HFILL }
 }
 , {
 & hf_h245_encryptionData , {
 "encryptionData" , "h245.encryptionData" , FT_UINT32 , BASE_DEC , VALS ( h245_EncryptionMode_vals ) , 0 , "EncryptionMode" , HFILL }
 }
 , {
 & hf_h245_h235Control , {
 "h235Control" , "h245.h235Control_element" , FT_NONE , BASE_NONE , NULL , 0 , "NonStandardParameter" , HFILL }
 }
 , {
 & hf_h245_h235Media , {
 "h235Media" , "h245.h235Media_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexedStream , {
 "multiplexedStream" , "h245.multiplexedStream_element" , FT_NONE , BASE_NONE , NULL , 0 , "MultiplexedStreamParameter" , HFILL }
 }
 , {
 & hf_h245_redundancyEncoding , {
 "redundancyEncoding" , "h245.redundancyEncoding_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplePayloadStream , {
 "multiplePayloadStream" , "h245.multiplePayloadStream_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_depFec , {
 "depFec" , "h245.depFec" , FT_UINT32 , BASE_DEC , VALS ( h245_DepFECData_vals ) , 0 , "DepFECData" , HFILL }
 }
 , {
 & hf_h245_fec , {
 "fec" , "h245.fec" , FT_UINT32 , BASE_DEC , VALS ( h245_FECData_vals ) , 0 , "FECData" , HFILL }
 }
 , {
 & hf_h245_mediaType , {
 "mediaType" , "h245.mediaType" , FT_UINT32 , BASE_DEC , VALS ( h245_T_mediaType_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_resourceID , {
 "resourceID" , "h245.resourceID" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_subChannelID , {
 "subChannelID" , "h245.subChannelID" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_8191" , HFILL }
 }
 , {
 & hf_h245_pcr_pid , {
 "pcr-pid" , "h245.pcr_pid" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_8191" , HFILL }
 }
 , {
 & hf_h245_programDescriptors , {
 "programDescriptors" , "h245.programDescriptors" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING" , HFILL }
 }
 , {
 & hf_h245_streamDescriptors , {
 "streamDescriptors" , "h245.streamDescriptors" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING" , HFILL }
 }
 , {
 & hf_h245_adaptationLayerType , {
 "adaptationLayerType" , "h245.adaptationLayerType" , FT_UINT32 , BASE_DEC , VALS ( h245_T_adaptationLayerType_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h223_al_type_al1Framed , {
 "al1Framed" , "h245.al1Framed_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_h223_al_type_al1Framed" , HFILL }
 }
 , {
 & hf_h245_h223_al_type_al1NotFramed , {
 "al1NotFramed" , "h245.al1NotFramed_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_h223_al_type_al1NotFramed" , HFILL }
 }
 , {
 & hf_h245_h223_al_type_al2WithoutSequenceNumbers , {
 "al2WithoutSequenceNumbers" , "h245.al2WithoutSequenceNumbers_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_h223_al_type_al2WithoutSequenceNumbers" , HFILL }
 }
 , {
 & hf_h245_h223_al_type_al2WithSequenceNumbers , {
 "al2WithSequenceNumbers" , "h245.al2WithSequenceNumbers_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_h223_al_type_al2WithSequenceNumbers" , HFILL }
 }
 , {
 & hf_h245_controlFieldOctets , {
 "controlFieldOctets" , "h245.controlFieldOctets" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_al3_sendBufferSize , {
 "sendBufferSize" , "h245.sendBufferSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "T_al3_sendBufferSize" , HFILL }
 }
 , {
 & hf_h245_h223_al_type_al3 , {
 "al3" , "h245.al3_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_h223_al_type_al3" , HFILL }
 }
 , {
 & hf_h245_h223_al_type_al1M , {
 "al1M" , "h245.al1M_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_h223_al_type_al1M" , HFILL }
 }
 , {
 & hf_h245_h223_al_type_al2M , {
 "al2M" , "h245.al2M_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_h223_al_type_al2M" , HFILL }
 }
 , {
 & hf_h245_h223_al_type_al3M , {
 "al3M" , "h245.al3M_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_h223_al_type_al3M" , HFILL }
 }
 , {
 & hf_h245_h223_lc_segmentableFlag , {
 "segmentableFlag" , "h245.segmentableFlag" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "T_h223_lc_segmentableFlag" , HFILL }
 }
 , {
 & hf_h245_transferMode , {
 "transferMode" , "h245.transferMode" , FT_UINT32 , BASE_DEC , VALS ( h245_T_transferMode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_framed , {
 "framed" , "h245.framed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_unframed , {
 "unframed" , "h245.unframed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_aL1HeaderFEC , {
 "headerFEC" , "h245.headerFEC" , FT_UINT32 , BASE_DEC , VALS ( h245_AL1HeaderFEC_vals ) , 0 , "AL1HeaderFEC" , HFILL }
 }
 , {
 & hf_h245_sebch16_7 , {
 "sebch16-7" , "h245.sebch16_7_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_golay24_12 , {
 "golay24-12" , "h245.golay24_12_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crcLength2 , {
 "crcLength" , "h245.crcLength" , FT_UINT32 , BASE_DEC , VALS ( h245_AL1CrcLength_vals ) , 0 , "AL1CrcLength" , HFILL }
 }
 , {
 & hf_h245_crc4bit , {
 "crc4bit" , "h245.crc4bit_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crc12bit , {
 "crc12bit" , "h245.crc12bit_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crc20bit , {
 "crc20bit" , "h245.crc20bit_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crc28bit , {
 "crc28bit" , "h245.crc28bit_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crc8bit , {
 "crc8bit" , "h245.crc8bit_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crc16bit , {
 "crc16bit" , "h245.crc16bit_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crc32bit , {
 "crc32bit" , "h245.crc32bit_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crcNotUsed , {
 "crcNotUsed" , "h245.crcNotUsed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rcpcCodeRate , {
 "rcpcCodeRate" , "h245.rcpcCodeRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_8_32" , HFILL }
 }
 , {
 & hf_h245_noArq , {
 "noArq" , "h245.noArq_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_typeIArq , {
 "typeIArq" , "h245.typeIArq_element" , FT_NONE , BASE_NONE , NULL , 0 , "H223AnnexCArqParameters" , HFILL }
 }
 , {
 & hf_h245_typeIIArq , {
 "typeIIArq" , "h245.typeIIArq_element" , FT_NONE , BASE_NONE , NULL , 0 , "H223AnnexCArqParameters" , HFILL }
 }
 , {
 & hf_h245_arqType , {
 "arqType" , "h245.arqType" , FT_UINT32 , BASE_DEC , VALS ( h245_ArqType_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_alsduSplitting , {
 "alsduSplitting" , "h245.alsduSplitting" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_rsCodeCorrection , {
 "rsCodeCorrection" , "h245.rsCodeCorrection" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_127" , HFILL }
 }
 , {
 & hf_h245_aL2HeaderFEC , {
 "headerFEC" , "h245.headerFEC" , FT_UINT32 , BASE_DEC , VALS ( h245_AL2HeaderFEC_vals ) , 0 , "AL2HeaderFEC" , HFILL }
 }
 , {
 & hf_h245_sebch16_5 , {
 "sebch16-5" , "h245.sebch16_5_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_headerFormat , {
 "headerFormat" , "h245.headerFormat" , FT_UINT32 , BASE_DEC , VALS ( h245_T_headerFormat_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crlength2 , {
 "crcLength" , "h245.crcLength" , FT_UINT32 , BASE_DEC , VALS ( h245_AL3CrcLength_vals ) , 0 , "AL3CrcLength" , HFILL }
 }
 , {
 & hf_h245_numberOfRetransmissions , {
 "numberOfRetransmissions" , "h245.numberOfRetransmissions" , FT_UINT32 , BASE_DEC , VALS ( h245_T_numberOfRetransmissions_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_finite , {
 "finite" , "h245.finite" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_16" , HFILL }
 }
 , {
 & hf_h245_infinite , {
 "infinite" , "h245.infinite_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sendBufferSize , {
 "sendBufferSize" , "h245.sendBufferSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_16777215" , HFILL }
 }
 , {
 & hf_h245_hdlcParameters , {
 "hdlcParameters" , "h245.hdlcParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , "V76HDLCParameters" , HFILL }
 }
 , {
 & hf_h245_suspendResume , {
 "suspendResume" , "h245.suspendResume" , FT_UINT32 , BASE_DEC , VALS ( h245_T_suspendResume_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_noSuspendResume , {
 "noSuspendResume" , "h245.noSuspendResume_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_suspendResumewAddress , {
 "suspendResumewAddress" , "h245.suspendResumewAddress_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_suspendResumewoAddress , {
 "suspendResumewoAddress" , "h245.suspendResumewoAddress_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_uIH , {
 "uIH" , "h245.uIH" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_v76_mode , {
 "mode" , "h245.mode" , FT_UINT32 , BASE_DEC , VALS ( h245_V76LCP_mode_vals ) , 0 , "V76LCP_mode" , HFILL }
 }
 , {
 & hf_h245_eRM , {
 "eRM" , "h245.eRM_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_windowSize , {
 "windowSize" , "h245.windowSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_127" , HFILL }
 }
 , {
 & hf_h245_recovery , {
 "recovery" , "h245.recovery" , FT_UINT32 , BASE_DEC , VALS ( h245_T_recovery_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rej , {
 "rej" , "h245.rej_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sREJ , {
 "sREJ" , "h245.sREJ_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mSREJ , {
 "mSREJ" , "h245.mSREJ_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_uNERM , {
 "uNERM" , "h245.uNERM_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v75Parameters , {
 "v75Parameters" , "h245.v75Parameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_crcLength , {
 "crcLength" , "h245.crcLength" , FT_UINT32 , BASE_DEC , VALS ( h245_CRCLength_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_n401 , {
 "n401" , "h245.n401" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4095" , HFILL }
 }
 , {
 & hf_h245_loopbackTestProcedure , {
 "loopbackTestProcedure" , "h245.loopbackTestProcedure" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_sessionID_0_255 , {
 "sessionID" , "h245.sessionID" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_associatedSessionID , {
 "associatedSessionID" , "h245.associatedSessionID" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_mediaChannel , {
 "mediaChannel" , "h245.mediaChannel" , FT_UINT32 , BASE_DEC , VALS ( h245_TransportAddress_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mediaGuaranteedDelivery , {
 "mediaGuaranteedDelivery" , "h245.mediaGuaranteedDelivery" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_mediaControlChannel , {
 "mediaControlChannel" , "h245.mediaControlChannel" , FT_UINT32 , BASE_DEC , VALS ( h245_TransportAddress_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mediaControlGuaranteedDelivery , {
 "mediaControlGuaranteedDelivery" , "h245.mediaControlGuaranteedDelivery" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_destination , {
 "destination" , "h245.destination_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_mediaPacketization , {
 "mediaPacketization" , "h245.mediaPacketization" , FT_UINT32 , BASE_DEC , VALS ( h245_T_mediaPacketization_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h261aVideoPacketizationFlag , {
 "h261aVideoPacketization" , "h245.h261aVideoPacketization_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rtpPayloadType , {
 "rtpPayloadType" , "h245.rtpPayloadType_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_source , {
 "source" , "h245.source_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_payloadDescriptor , {
 "payloadDescriptor" , "h245.payloadDescriptor" , FT_UINT32 , BASE_DEC , VALS ( h245_T_payloadDescriptor_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rfc_number , {
 "rfc-number" , "h245.rfc_number" , FT_UINT32 , BASE_DEC , VALS ( h245_RFC_number_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_oid , {
 "oid" , "h245.oid" , FT_OID , BASE_NONE , NULL , 0 , "OBJECT_IDENTIFIER" , HFILL }
 }
 , {
 & hf_h245_rtpPayloadType_01 , {
 "payloadType" , "h245.payloadType" , FT_UINT32 , BASE_DEC , NULL , 0 , "T_rtpPayloadType" , HFILL }
 }
 , {
 & hf_h245_secondaryEncoding , {
 "secondaryEncoding" , "h245.secondaryEncoding" , FT_UINT32 , BASE_DEC , VALS ( h245_DataType_vals ) , 0 , "DataType" , HFILL }
 }
 , {
 & hf_h245_rtpRedundancyEncoding , {
 "rtpRedundancyEncoding" , "h245.rtpRedundancyEncoding_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_primary , {
 "primary" , "h245.primary_element" , FT_NONE , BASE_NONE , NULL , 0 , "RedundancyEncodingElement" , HFILL }
 }
 , {
 & hf_h245_secondary , {
 "secondary" , "h245.secondary" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_RedundancyEncodingElement" , HFILL }
 }
 , {
 & hf_h245_secondary_item , {
 "RedundancyEncodingElement" , "h245.RedundancyEncodingElement_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_payloadType , {
 "payloadType" , "h245.payloadType" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_127" , HFILL }
 }
 , {
 & hf_h245_elements , {
 "elements" , "h245.elements" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_MultiplePayloadStreamElement" , HFILL }
 }
 , {
 & hf_h245_elements_item , {
 "MultiplePayloadStreamElement" , "h245.MultiplePayloadStreamElement_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dep_rfc2733 , {
 "rfc2733" , "h245.rfc2733_element" , FT_NONE , BASE_NONE , NULL , 0 , "RFC2733Data" , HFILL }
 }
 , {
 & hf_h245_fec_data_mode , {
 "mode" , "h245.mode" , FT_UINT32 , BASE_DEC , VALS ( h245_FECdata_mode_vals ) , 0 , "FECdata_mode" , HFILL }
 }
 , {
 & hf_h245_redundancyEncodingFlag , {
 "redundancyEncoding" , "h245.redundancyEncoding_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_differentPort , {
 "differentPort" , "h245.differentPort_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_protectedSessionID , {
 "protectedSessionID" , "h245.protectedSessionID" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_protectedPayloadType , {
 "protectedPayloadType" , "h245.protectedPayloadType" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_127" , HFILL }
 }
 , {
 & hf_h245_samePort , {
 "samePort" , "h245.samePort_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_separateStream , {
 "separateStream" , "h245.separateStream" , FT_UINT32 , BASE_DEC , VALS ( h245_DepSeparateStream_vals ) , 0 , "DepSeparateStream" , HFILL }
 }
 , {
 & hf_h245_rfc2733 , {
 "rfc2733" , "h245.rfc2733_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_pktMode , {
 "pktMode" , "h245.pktMode" , FT_UINT32 , BASE_DEC , VALS ( h245_T_pktMode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rfc2198coding , {
 "rfc2198coding" , "h245.rfc2198coding_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mode_rfc2733sameport , {
 "rfc2733sameport" , "h245.rfc2733sameport_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_mode_rfc2733sameport" , HFILL }
 }
 , {
 & hf_h245_mode_rfc2733diffport , {
 "rfc2733diffport" , "h245.rfc2733diffport_element" , FT_NONE , BASE_NONE , NULL , 0 , "T_mode_rfc2733diffport" , HFILL }
 }
 , {
 & hf_h245_protectedChannel , {
 "protectedChannel" , "h245.protectedChannel" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_unicastAddress , {
 "unicastAddress" , "h245.unicastAddress" , FT_UINT32 , BASE_DEC , VALS ( h245_UnicastAddress_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multicastAddress , {
 "multicastAddress" , "h245.multicastAddress" , FT_UINT32 , BASE_DEC , VALS ( h245_MulticastAddress_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_iPAddress , {
 "iPAddress" , "h245.iPAddress_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_ip4_network , {
 "network" , "h245.network" , FT_IPv4 , BASE_NONE , NULL , 0 , "Ipv4_network" , HFILL }
 }
 , {
 & hf_h245_tsapIdentifier , {
 "tsapIdentifier" , "h245.tsapIdentifier" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_iPXAddress , {
 "iPXAddress" , "h245.iPXAddress_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_node , {
 "node" , "h245.node" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_6" , HFILL }
 }
 , {
 & hf_h245_netnum , {
 "netnum" , "h245.netnum" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_4" , HFILL }
 }
 , {
 & hf_h245_ipx_tsapIdentifier , {
 "tsapIdentifier" , "h245.tsapIdentifier" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_2" , HFILL }
 }
 , {
 & hf_h245_iP6Address , {
 "iP6Address" , "h245.iP6Address_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_ip6_network , {
 "network" , "h245.network" , FT_IPv6 , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_16" , HFILL }
 }
 , {
 & hf_h245_ipv6_tsapIdentifier , {
 "tsapIdentifier" , "h245.tsapIdentifier" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_netBios , {
 "netBios" , "h245.netBios" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_16" , HFILL }
 }
 , {
 & hf_h245_iPSourceRouteAddress , {
 "iPSourceRouteAddress" , "h245.iPSourceRouteAddress_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_routing , {
 "routing" , "h245.routing" , FT_UINT32 , BASE_DEC , VALS ( h245_T_routing_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_strict , {
 "strict" , "h245.strict_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_loose , {
 "loose" , "h245.loose_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_network , {
 "network" , "h245.network" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_4" , HFILL }
 }
 , {
 & hf_h245_iPSrcRoute_tsapIdentifier , {
 "tsapIdentifier" , "h245.tsapIdentifier" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_route , {
 "route" , "h245.route" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_route_item , {
 "route item" , "h245.route_item" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_4" , HFILL }
 }
 , {
 & hf_h245_nsap , {
 "nsap" , "h245.nsap" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1_20" , HFILL }
 }
 , {
 & hf_h245_nonStandardAddress , {
 "nonStandardAddress" , "h245.nonStandardAddress_element" , FT_NONE , BASE_NONE , NULL , 0 , "NonStandardParameter" , HFILL }
 }
 , {
 & hf_h245_mIPAddress , {
 "iPAddress" , "h245.iPAddress_element" , FT_NONE , BASE_NONE , NULL , 0 , "MIPAddress" , HFILL }
 }
 , {
 & hf_h245_mip4_network , {
 "network" , "h245.network" , FT_IPv4 , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_4" , HFILL }
 }
 , {
 & hf_h245_multicast_tsapIdentifier , {
 "tsapIdentifier" , "h245.tsapIdentifier" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_mIP6Address , {
 "iP6Address" , "h245.iP6Address_element" , FT_NONE , BASE_NONE , NULL , 0 , "MIP6Address" , HFILL }
 }
 , {
 & hf_h245_mip6_network , {
 "network" , "h245.network" , FT_IPv6 , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_16" , HFILL }
 }
 , {
 & hf_h245_multicast_IPv6_tsapIdentifier , {
 "tsapIdentifier" , "h245.tsapIdentifier" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_synchFlag , {
 "synchFlag" , "h245.synchFlag" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_h235Key , {
 "h235Key" , "h245.h235Key" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1_65535" , HFILL }
 }
 , {
 & hf_h245_escrowentry , {
 "escrowentry" , "h245.escrowentry" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_SIZE_1_256_OF_EscrowData" , HFILL }
 }
 , {
 & hf_h245_escrowentry_item , {
 "EscrowData" , "h245.EscrowData_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericParameter , {
 "genericParameter" , "h245.genericParameter_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_escrowID , {
 "escrowID" , "h245.escrowID" , FT_OID , BASE_NONE , NULL , 0 , "OBJECT_IDENTIFIER" , HFILL }
 }
 , {
 & hf_h245_escrowValue , {
 "escrowValue" , "h245.escrowValue" , FT_BYTES , BASE_NONE , NULL , 0 , "BIT_STRING_SIZE_1_65535" , HFILL }
 }
 , {
 & hf_h245_olc_ack_fw_lcn , {
 "forwardLogicalChannelNumber" , "h245.forwardLogicalChannelNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "OLC_ack_fw_lcn" , HFILL }
 }
 , {
 & hf_h245_olc_ack_reverseLogicalChannelParameters , {
 "reverseLogicalChannelParameters" , "h245.reverseLogicalChannelParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , "OLC_ack_reverseLogicalChannelParameters" , HFILL }
 }
 , {
 & hf_h245_reverseLogicalChannelNumber , {
 "reverseLogicalChannelNumber" , "h245.reverseLogicalChannelNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_olc_ack_multiplexParameters , {
 "multiplexParameters" , "h245.multiplexParameters" , FT_UINT32 , BASE_DEC , VALS ( h245_T_olc_ack_multiplexParameters_vals ) , 0 , "T_olc_ack_multiplexParameters" , HFILL }
 }
 , {
 & hf_h245_forwardMultiplexAckParameters , {
 "forwardMultiplexAckParameters" , "h245.forwardMultiplexAckParameters" , FT_UINT32 , BASE_DEC , VALS ( h245_T_forwardMultiplexAckParameters_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h2250LogicalChannelAckParameters , {
 "h2250LogicalChannelAckParameters" , "h245.h2250LogicalChannelAckParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_forwardLogicalChannelNumber , {
 "forwardLogicalChannelNumber" , "h245.forwardLogicalChannelNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_olc_rej_cause , {
 "cause" , "h245.cause" , FT_UINT32 , BASE_DEC , VALS ( h245_OpenLogicalChannelRejectCause_vals ) , 0 , "OpenLogicalChannelRejectCause" , HFILL }
 }
 , {
 & hf_h245_unsuitableReverseParameters , {
 "unsuitableReverseParameters" , "h245.unsuitableReverseParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dataTypeNotSupported , {
 "dataTypeNotSupported" , "h245.dataTypeNotSupported_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dataTypeNotAvailable , {
 "dataTypeNotAvailable" , "h245.dataTypeNotAvailable_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_unknownDataType , {
 "unknownDataType" , "h245.unknownDataType_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dataTypeALCombinationNotSupported , {
 "dataTypeALCombinationNotSupported" , "h245.dataTypeALCombinationNotSupported_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multicastChannelNotAllowed , {
 "multicastChannelNotAllowed" , "h245.multicastChannelNotAllowed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_insufficientBandwidth , {
 "insufficientBandwidth" , "h245.insufficientBandwidth_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_separateStackEstablishmentFailed , {
 "separateStackEstablishmentFailed" , "h245.separateStackEstablishmentFailed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_invalidSessionID , {
 "invalidSessionID" , "h245.invalidSessionID_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_masterSlaveConflict , {
 "masterSlaveConflict" , "h245.masterSlaveConflict_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_waitForCommunicationMode , {
 "waitForCommunicationMode" , "h245.waitForCommunicationMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_invalidDependentChannel , {
 "invalidDependentChannel" , "h245.invalidDependentChannel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_replacementForRejected , {
 "replacementForRejected" , "h245.replacementForRejected_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_securityDenied , {
 "securityDenied" , "h245.securityDenied_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_qoSControlNotSupported , {
 "qoSControlNotSupported" , "h245.qoSControlNotSupported_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sessionID , {
 "sessionID" , "h245.sessionID" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_ack_mediaChannel , {
 "mediaChannel" , "h245.mediaChannel" , FT_UINT32 , BASE_DEC , VALS ( h245_TransportAddress_vals ) , 0 , "Ack_mediaChannel" , HFILL }
 }
 , {
 & hf_h245_ack_mediaControlChannel , {
 "mediaControlChannel" , "h245.mediaControlChannel" , FT_UINT32 , BASE_DEC , VALS ( h245_TransportAddress_vals ) , 0 , "Ack_mediaControlChannel" , HFILL }
 }
 , {
 & hf_h245_flowControlToZero , {
 "flowControlToZero" , "h245.flowControlToZero" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_cLC_source , {
 "source" , "h245.source" , FT_UINT32 , BASE_DEC , VALS ( h245_T_cLC_source_vals ) , 0 , "T_cLC_source" , HFILL }
 }
 , {
 & hf_h245_user , {
 "user" , "h245.user_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_lcse , {
 "lcse" , "h245.lcse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_clc_reason , {
 "reason" , "h245.reason" , FT_UINT32 , BASE_DEC , VALS ( h245_Clc_reason_vals ) , 0 , "Clc_reason" , HFILL }
 }
 , {
 & hf_h245_unknown , {
 "unknown" , "h245.unknown_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_reopen , {
 "reopen" , "h245.reopen_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_reservationFailure , {
 "reservationFailure" , "h245.reservationFailure_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_networkErrorCode , {
 "networkErrorCode" , "h245.networkErrorCode" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_qosCapability , {
 "qosCapability" , "h245.qosCapability_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_reason , {
 "reason" , "h245.reason" , FT_UINT32 , BASE_DEC , VALS ( h245_T_reason_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_normal , {
 "normal" , "h245.normal_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_req_chan_clos_rej_cause , {
 "cause" , "h245.cause" , FT_UINT32 , BASE_DEC , VALS ( h245_RequestChannelCloseRejectCause_vals ) , 0 , "RequestChannelCloseRejectCause" , HFILL }
 }
 , {
 & hf_h245_multiplexEntryDescriptors , {
 "multiplexEntryDescriptors" , "h245.multiplexEntryDescriptors" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_15_OF_MultiplexEntryDescriptor" , HFILL }
 }
 , {
 & hf_h245_multiplexEntryDescriptors_item , {
 "MultiplexEntryDescriptor" , "h245.MultiplexEntryDescriptor_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexTableEntryNumber , {
 "multiplexTableEntryNumber" , "h245.multiplexTableEntryNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_elementList , {
 "elementList" , "h245.elementList" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_elementList_item , {
 "MultiplexElement" , "h245.MultiplexElement_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_me_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_Me_type_vals ) , 0 , "Me_type" , HFILL }
 }
 , {
 & hf_h245_logicalChannelNum , {
 "logicalChannelNumber" , "h245.logicalChannelNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "T_logicalChannelNum" , HFILL }
 }
 , {
 & hf_h245_subElementList , {
 "subElementList" , "h245.subElementList" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_subElementList_item , {
 "MultiplexElement" , "h245.MultiplexElement_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_me_repeatCount , {
 "repeatCount" , "h245.repeatCount" , FT_UINT32 , BASE_DEC , VALS ( h245_ME_repeatCount_vals ) , 0 , "ME_repeatCount" , HFILL }
 }
 , {
 & hf_h245_me_repeatCount_finite , {
 "finite" , "h245.finite" , FT_UINT32 , BASE_DEC , NULL , 0 , "ME_finiteRepeatCount" , HFILL }
 }
 , {
 & hf_h245_untilClosingFlag , {
 "untilClosingFlag" , "h245.untilClosingFlag_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexTableEntryNumbers , {
 "multiplexTableEntryNumber" , "h245.multiplexTableEntryNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_15_OF_MultiplexTableEntryNumber" , HFILL }
 }
 , {
 & hf_h245_multiplexTableEntryNumbers_item , {
 "MultiplexTableEntryNumber" , "h245.MultiplexTableEntryNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sendRejectionDescriptions , {
 "rejectionDescriptions" , "h245.rejectionDescriptions" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_15_OF_MultiplexEntryRejectionDescriptions" , HFILL }
 }
 , {
 & hf_h245_sendRejectionDescriptions_item , {
 "MultiplexEntryRejectionDescriptions" , "h245.MultiplexEntryRejectionDescriptions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mux_rej_cause , {
 "cause" , "h245.cause" , FT_UINT32 , BASE_DEC , VALS ( h245_MultiplexEntryRejectionDescriptionsCause_vals ) , 0 , "MultiplexEntryRejectionDescriptionsCause" , HFILL }
 }
 , {
 & hf_h245_unspecifiedCause , {
 "unspecifiedCause" , "h245.unspecifiedCause_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_descriptorTooComplex , {
 "descriptorTooComplex" , "h245.descriptorTooComplex_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_entryNumbers , {
 "entryNumbers" , "h245.entryNumbers" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_15_OF_MultiplexTableEntryNumber" , HFILL }
 }
 , {
 & hf_h245_entryNumbers_item , {
 "MultiplexTableEntryNumber" , "h245.MultiplexTableEntryNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rejectionDescriptions , {
 "rejectionDescriptions" , "h245.rejectionDescriptions" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_15_OF_RequestMultiplexEntryRejectionDescriptions" , HFILL }
 }
 , {
 & hf_h245_rejectionDescriptions_item , {
 "RequestMultiplexEntryRejectionDescriptions" , "h245.RequestMultiplexEntryRejectionDescriptions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_req_mux_rej_cause , {
 "cause" , "h245.cause" , FT_UINT32 , BASE_DEC , VALS ( h245_RequestMultiplexEntryRejectionDescriptionsCause_vals ) , 0 , "RequestMultiplexEntryRejectionDescriptionsCause" , HFILL }
 }
 , {
 & hf_h245_requestedModes , {
 "requestedModes" , "h245.requestedModes" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_SIZE_1_256_OF_ModeDescription" , HFILL }
 }
 , {
 & hf_h245_requestedModes_item , {
 "ModeDescription" , "h245.ModeDescription" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_req_mode_ack_response , {
 "response" , "h245.response" , FT_UINT32 , BASE_DEC , VALS ( h245_Req_mode_ack_response_vals ) , 0 , "Req_mode_ack_response" , HFILL }
 }
 , {
 & hf_h245_willTransmitMostPreferredMode , {
 "willTransmitMostPreferredMode" , "h245.willTransmitMostPreferredMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_willTransmitLessPreferredMode , {
 "willTransmitLessPreferredMode" , "h245.willTransmitLessPreferredMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_req_rej_cause , {
 "cause" , "h245.cause" , FT_UINT32 , BASE_DEC , VALS ( h245_RequestModeRejectCause_vals ) , 0 , "RequestModeRejectCause" , HFILL }
 }
 , {
 & hf_h245_modeUnavailable , {
 "modeUnavailable" , "h245.modeUnavailable_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multipointConstraint , {
 "multipointConstraint" , "h245.multipointConstraint_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestDenied , {
 "requestDenied" , "h245.requestDenied_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_ModeDescription_item , {
 "ModeElement" , "h245.ModeElement_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoMode , {
 "videoMode" , "h245.videoMode" , FT_UINT32 , BASE_DEC , VALS ( h245_VideoMode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioMode , {
 "audioMode" , "h245.audioMode" , FT_UINT32 , BASE_DEC , VALS ( h245_AudioMode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dataMode , {
 "dataMode" , "h245.dataMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptionMode , {
 "encryptionMode" , "h245.encryptionMode" , FT_UINT32 , BASE_DEC , VALS ( h245_EncryptionMode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h235Mode , {
 "h235Mode" , "h245.h235Mode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexedStreamMode , {
 "multiplexedStreamMode" , "h245.multiplexedStreamMode_element" , FT_NONE , BASE_NONE , NULL , 0 , "MultiplexedStreamParameter" , HFILL }
 }
 , {
 & hf_h245_redundancyEncodingDTMode , {
 "redundancyEncodingDTMode" , "h245.redundancyEncodingDTMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplePayloadStreamMode , {
 "multiplePayloadStreamMode" , "h245.multiplePayloadStreamMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_depFecMode , {
 "depFecMode" , "h245.depFecMode" , FT_UINT32 , BASE_DEC , VALS ( h245_DepFECMode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fecMode , {
 "fecMode" , "h245.fecMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_ModeElementType_vals ) , 0 , "ModeElementType" , HFILL }
 }
 , {
 & hf_h245_h223ModeParameters , {
 "h223ModeParameters" , "h245.h223ModeParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v76ModeParameters , {
 "v76ModeParameters" , "h245.v76ModeParameters" , FT_UINT32 , BASE_DEC , VALS ( h245_V76ModeParameters_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h2250ModeParameters , {
 "h2250ModeParameters" , "h245.h2250ModeParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericModeParameters , {
 "genericModeParameters" , "h245.genericModeParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_multiplexedStreamModeParameters , {
 "multiplexedStreamModeParameters" , "h245.multiplexedStreamModeParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_logicalChannelNumber , {
 "logicalChannelNumber" , "h245.logicalChannelNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mediaMode , {
 "mediaMode" , "h245.mediaMode" , FT_UINT32 , BASE_DEC , VALS ( h245_T_mediaMode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_prmary_dtmode , {
 "primary" , "h245.primary_element" , FT_NONE , BASE_NONE , NULL , 0 , "RedundancyEncodingDTModeElement" , HFILL }
 }
 , {
 & hf_h245_secondaryDTM , {
 "secondary" , "h245.secondary" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_RedundancyEncodingDTModeElement" , HFILL }
 }
 , {
 & hf_h245_secondaryDTM_item , {
 "RedundancyEncodingDTModeElement" , "h245.RedundancyEncodingDTModeElement_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_re_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_Re_type_vals ) , 0 , "Re_type" , HFILL }
 }
 , {
 & hf_h245_mpsmElements , {
 "elements" , "h245.elements" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_MultiplePayloadStreamElementMode" , HFILL }
 }
 , {
 & hf_h245_mpsmElements_item , {
 "MultiplePayloadStreamElementMode" , "h245.MultiplePayloadStreamElementMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rfc2733Mode , {
 "rfc2733Mode" , "h245.rfc2733Mode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fec_mode , {
 "mode" , "h245.mode" , FT_UINT32 , BASE_DEC , VALS ( h245_FEC_mode_vals ) , 0 , "FEC_mode" , HFILL }
 }
 , {
 & hf_h245_protectedElement , {
 "protectedElement" , "h245.protectedElement" , FT_UINT32 , BASE_DEC , VALS ( h245_ModeElementType_vals ) , 0 , "ModeElementType" , HFILL }
 }
 , {
 & hf_h245_adaptationLayer , {
 "adaptationLayerType" , "h245.adaptationLayerType" , FT_UINT32 , BASE_DEC , VALS ( h245_AdaptationLayerType_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_al1Framed , {
 "al1Framed" , "h245.al1Framed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_al1NotFramed , {
 "al1NotFramed" , "h245.al1NotFramed_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_al2WithoutSequenceNumbers , {
 "al2WithoutSequenceNumbers" , "h245.al2WithoutSequenceNumbers_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_al2WithSequenceNumbers , {
 "al2WithSequenceNumbers" , "h245.al2WithSequenceNumbers_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_al3 , {
 "al3" , "h245.al3_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_al1M , {
 "al1M" , "h245.al1M_element" , FT_NONE , BASE_NONE , NULL , 0 , "H223AL1MParameters" , HFILL }
 }
 , {
 & hf_h245_al2M , {
 "al2M" , "h245.al2M_element" , FT_NONE , BASE_NONE , NULL , 0 , "H223AL2MParameters" , HFILL }
 }
 , {
 & hf_h245_al3M , {
 "al3M" , "h245.al3M_element" , FT_NONE , BASE_NONE , NULL , 0 , "H223AL3MParameters" , HFILL }
 }
 , {
 & hf_h245_segmentableFlag , {
 "segmentableFlag" , "h245.segmentableFlag" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_redundancyEncodingMode , {
 "redundancyEncodingMode" , "h245.redundancyEncodingMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_secondaryEncodingMode , {
 "secondaryEncoding" , "h245.secondaryEncoding" , FT_UINT32 , BASE_DEC , VALS ( h245_T_secondaryEncodingMode_vals ) , 0 , "T_secondaryEncodingMode" , HFILL }
 }
 , {
 & hf_h245_h261VideoMode , {
 "h261VideoMode" , "h245.h261VideoMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h262VideoMode , {
 "h262VideoMode" , "h245.h262VideoMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h263VideoMode , {
 "h263VideoMode" , "h245.h263VideoMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_is11172VideoMode , {
 "is11172VideoMode" , "h245.is11172VideoMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericVideoMode , {
 "genericVideoMode" , "h245.genericVideoMode_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_h261_resolution , {
 "resolution" , "h245.resolution" , FT_UINT32 , BASE_DEC , VALS ( h245_H261Resolution_vals ) , 0 , "H261Resolution" , HFILL }
 }
 , {
 & hf_h245_qcif , {
 "qcif" , "h245.qcif_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cif , {
 "cif" , "h245.cif_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel , {
 "profileAndLevel" , "h245.profileAndLevel" , FT_UINT32 , BASE_DEC , VALS ( h245_T_profileAndLevel_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_SPatMLMode , {
 "profileAndLevel-SPatML" , "h245.profileAndLevel_SPatML_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_MPatLLMode , {
 "profileAndLevel-MPatLL" , "h245.profileAndLevel_MPatLL_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_MPatMLMode , {
 "profileAndLevel-MPatML" , "h245.profileAndLevel_MPatML_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_MPatH_14Mode , {
 "profileAndLevel-MPatH-14" , "h245.profileAndLevel_MPatH_14_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_MPatHLMode , {
 "profileAndLevel-MPatHL" , "h245.profileAndLevel_MPatHL_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_SNRatLLMode , {
 "profileAndLevel-SNRatLL" , "h245.profileAndLevel_SNRatLL_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_SNRatMLMode , {
 "profileAndLevel-SNRatML" , "h245.profileAndLevel_SNRatML_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_SpatialatH_14Mode , {
 "profileAndLevel-SpatialatH-14" , "h245.profileAndLevel_SpatialatH_14_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_HPatMLMode , {
 "profileAndLevel-HPatML" , "h245.profileAndLevel_HPatML_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_HPatH_14Mode , {
 "profileAndLevel-HPatH-14" , "h245.profileAndLevel_HPatH_14_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_profileAndLevel_HPatHLMode , {
 "profileAndLevel-HPatHL" , "h245.profileAndLevel_HPatHL_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h263_resolution , {
 "resolution" , "h245.resolution" , FT_UINT32 , BASE_DEC , VALS ( h245_H263Resolution_vals ) , 0 , "H263Resolution" , HFILL }
 }
 , {
 & hf_h245_sqcif , {
 "sqcif" , "h245.sqcif_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cif4 , {
 "cif4" , "h245.cif4_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cif16 , {
 "cif16" , "h245.cif16_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_custom_res , {
 "custom" , "h245.custom_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g711Alaw64k_mode , {
 "g711Alaw64k" , "h245.g711Alaw64k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g711Alaw56k_mode , {
 "g711Alaw56k" , "h245.g711Alaw56k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g711Ulaw64k_mode , {
 "g711Ulaw64k" , "h245.g711Ulaw64k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g711Ulaw56k_mode , {
 "g711Ulaw56k" , "h245.g711Ulaw56k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g722_64k_mode , {
 "g722-64k" , "h245.g722_64k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g722_56k_mode , {
 "g722-56k" , "h245.g722_56k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g722_48k_mode , {
 "g722-48k" , "h245.g722_48k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g728_mode , {
 "g728" , "h245.g728_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g729_mode , {
 "g729" , "h245.g729_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g729AnnexA_mode , {
 "g729AnnexA" , "h245.g729AnnexA_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g7231_mode , {
 "g7231" , "h245.g7231" , FT_UINT32 , BASE_DEC , VALS ( h245_Mode_g7231_vals ) , 0 , "Mode_g7231" , HFILL }
 }
 , {
 & hf_h245_noSilenceSuppressionLowRate , {
 "noSilenceSuppressionLowRate" , "h245.noSilenceSuppressionLowRate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_noSilenceSuppressionHighRate , {
 "noSilenceSuppressionHighRate" , "h245.noSilenceSuppressionHighRate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_silenceSuppressionLowRate , {
 "silenceSuppressionLowRate" , "h245.silenceSuppressionLowRate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_silenceSuppressionHighRate , {
 "silenceSuppressionHighRate" , "h245.silenceSuppressionHighRate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_is11172AudioMode , {
 "is11172AudioMode" , "h245.is11172AudioMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_is13818AudioMode , {
 "is13818AudioMode" , "h245.is13818AudioMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_g7231AnnexCMode , {
 "g7231AnnexCMode" , "h245.g7231AnnexCMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericAudioMode , {
 "genericAudioMode" , "h245.genericAudioMode_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_vbd_mode , {
 "vbd" , "h245.vbd_element" , FT_NONE , BASE_NONE , NULL , 0 , "VBDMode" , HFILL }
 }
 , {
 & hf_h245_audioLayer , {
 "audioLayer" , "h245.audioLayer" , FT_UINT32 , BASE_DEC , VALS ( h245_T_audioLayer_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioLayer1Mode , {
 "audioLayer1" , "h245.audioLayer1_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioLayer2Mode , {
 "audioLayer2" , "h245.audioLayer2_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioLayer3Mode , {
 "audioLayer3" , "h245.audioLayer3_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioSampling , {
 "audioSampling" , "h245.audioSampling" , FT_UINT32 , BASE_DEC , VALS ( h245_T_audioSampling_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioSampling32kMode , {
 "audioSampling32k" , "h245.audioSampling32k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioSampling44k1Mode , {
 "audioSampling44k1" , "h245.audioSampling44k1_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioSampling48kMode , {
 "audioSampling48k" , "h245.audioSampling48k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_is11172multichannelType , {
 "multichannelType" , "h245.multichannelType" , FT_UINT32 , BASE_DEC , VALS ( h245_IS11172_multichannelType_vals ) , 0 , "IS11172_multichannelType" , HFILL }
 }
 , {
 & hf_h245_singleChannelMode , {
 "singleChannel" , "h245.singleChannel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_twoChannelStereo , {
 "twoChannelStereo" , "h245.twoChannelStereo_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_twoChannelDual , {
 "twoChannelDual" , "h245.twoChannelDual_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioLayerMode , {
 "audioLayer" , "h245.audioLayer" , FT_UINT32 , BASE_DEC , VALS ( h245_IS13818AudioLayer_vals ) , 0 , "IS13818AudioLayer" , HFILL }
 }
 , {
 & hf_h245_audioSamplingMode , {
 "audioSampling" , "h245.audioSampling" , FT_UINT32 , BASE_DEC , VALS ( h245_IS13818AudioSampling_vals ) , 0 , "IS13818AudioSampling" , HFILL }
 }
 , {
 & hf_h245_audioSampling16kMode , {
 "audioSampling16k" , "h245.audioSampling16k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioSampling22k05Mode , {
 "audioSampling22k05" , "h245.audioSampling22k05_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_audioSampling24kMode , {
 "audioSampling24k" , "h245.audioSampling24k_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_is13818MultichannelType , {
 "multichannelType" , "h245.multichannelType" , FT_UINT32 , BASE_DEC , VALS ( h245_IS13818MultichannelType_vals ) , 0 , "IS13818MultichannelType" , HFILL }
 }
 , {
 & hf_h245_threeChannels2_1Mode , {
 "threeChannels2-1" , "h245.threeChannels2_1_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_threeChannels3_0Mode , {
 "threeChannels3-0" , "h245.threeChannels3_0_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fourChannels2_0_2_0Mode , {
 "fourChannels2-0-2-0" , "h245.fourChannels2_0_2_0_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fourChannels2_2Mode , {
 "fourChannels2-2" , "h245.fourChannels2_2_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fourChannels3_1Mode , {
 "fourChannels3-1" , "h245.fourChannels3_1_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fiveChannels3_0_2_0Mode , {
 "fiveChannels3-0-2-0" , "h245.fiveChannels3_0_2_0_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fiveChannels3_2Mode , {
 "fiveChannels3-2" , "h245.fiveChannels3_2_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_vbd_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_AudioMode_vals ) , 0 , "AudioMode" , HFILL }
 }
 , {
 & hf_h245_datamodeapplication , {
 "application" , "h245.application" , FT_UINT32 , BASE_DEC , VALS ( h245_DataModeApplication_vals ) , 0 , "DataModeApplication" , HFILL }
 }
 , {
 & hf_h245_t84DataProtocolCapability , {
 "t84" , "h245.t84" , FT_UINT32 , BASE_DEC , VALS ( DataProtocolCapability_vals ) , 0 , "DataProtocolCapability" , HFILL }
 }
 , {
 & hf_h245_t38faxDataProtocolCapability , {
 "t38fax" , "h245.t38fax_element" , FT_NONE , BASE_NONE , NULL , 0 , "T38faxApp" , HFILL }
 }
 , {
 & hf_h245_genericDataMode , {
 "genericDataMode" , "h245.genericDataMode_element" , FT_NONE , BASE_NONE , NULL , 0 , "GenericCapability" , HFILL }
 }
 , {
 & hf_h245_bitRate_0_4294967295 , {
 "bitRate" , "h245.bitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4294967295" , HFILL }
 }
 , {
 & hf_h245_h233Encryption , {
 "h233Encryption" , "h245.h233Encryption_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mlr_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_Mlr_type_vals ) , 0 , "Mlr_type" , HFILL }
 }
 , {
 & hf_h245_systemLoop , {
 "systemLoop" , "h245.systemLoop_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mediaLoop , {
 "mediaLoop" , "h245.mediaLoop" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_logicalChannelLoop , {
 "logicalChannelLoop" , "h245.logicalChannelLoop" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_mla_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_Mla_type_vals ) , 0 , "Mla_type" , HFILL }
 }
 , {
 & hf_h245_mlrej_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_Mlrej_type_vals ) , 0 , "Mlrej_type" , HFILL }
 }
 , {
 & hf_h245_maintloop_rej_cause , {
 "cause" , "h245.cause" , FT_UINT32 , BASE_DEC , VALS ( h245_MaintenanceLoopRejectCause_vals ) , 0 , "MaintenanceLoopRejectCause" , HFILL }
 }
 , {
 & hf_h245_canNotPerformLoop , {
 "canNotPerformLoop" , "h245.canNotPerformLoop_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_communicationModeTable , {
 "communicationModeTable" , "h245.communicationModeTable" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_256_OF_CommunicationModeTableEntry" , HFILL }
 }
 , {
 & hf_h245_communicationModeTable_item , {
 "CommunicationModeTableEntry" , "h245.CommunicationModeTableEntry_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalLabel , {
 "terminalLabel" , "h245.terminalLabel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sessionDescription , {
 "sessionDescription" , "h245.sessionDescription" , FT_STRING , BASE_NONE , NULL , 0 , "BMPString_SIZE_1_128" , HFILL }
 }
 , {
 & hf_h245_entryDataType , {
 "dataType" , "h245.dataType" , FT_UINT32 , BASE_DEC , VALS ( h245_T_entryDataType_vals ) , 0 , "T_entryDataType" , HFILL }
 }
 , {
 & hf_h245_cm_mediaChannel , {
 "mediaChannel" , "h245.mediaChannel" , FT_UINT32 , BASE_DEC , VALS ( h245_TransportAddress_vals ) , 0 , "Cm_mediaChannel" , HFILL }
 }
 , {
 & hf_h245_cm_mediaControlChannel , {
 "mediaControlChannel" , "h245.mediaControlChannel" , FT_UINT32 , BASE_DEC , VALS ( h245_TransportAddress_vals ) , 0 , "TransportAddress" , HFILL }
 }
 , {
 & hf_h245_sessionDependency , {
 "sessionDependency" , "h245.sessionDependency" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_terminalListRequest , {
 "terminalListRequest" , "h245.terminalListRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_makeMeChair , {
 "makeMeChair" , "h245.makeMeChair_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelMakeMeChair , {
 "cancelMakeMeChair" , "h245.cancelMakeMeChair_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dropTerminal , {
 "dropTerminal" , "h245.dropTerminal_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_requestTerminalID , {
 "requestTerminalID" , "h245.requestTerminalID_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_enterH243Password , {
 "enterH243Password" , "h245.enterH243Password_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_enterH243TerminalID , {
 "enterH243TerminalID" , "h245.enterH243TerminalID_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_enterH243ConferenceID , {
 "enterH243ConferenceID" , "h245.enterH243ConferenceID_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_enterExtensionAddress , {
 "enterExtensionAddress" , "h245.enterExtensionAddress_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestChairTokenOwner , {
 "requestChairTokenOwner" , "h245.requestChairTokenOwner_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestTerminalCertificate , {
 "requestTerminalCertificate" , "h245.requestTerminalCertificate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_certSelectionCriteria , {
 "certSelectionCriteria" , "h245.certSelectionCriteria" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sRandom , {
 "sRandom" , "h245.sRandom" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_4294967295" , HFILL }
 }
 , {
 & hf_h245_broadcastMyLogicalChannel , {
 "broadcastMyLogicalChannel" , "h245.broadcastMyLogicalChannel" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_makeTerminalBroadcaster , {
 "makeTerminalBroadcaster" , "h245.makeTerminalBroadcaster_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_sendThisSource , {
 "sendThisSource" , "h245.sendThisSource_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_requestAllTerminalIDs , {
 "requestAllTerminalIDs" , "h245.requestAllTerminalIDs_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_remoteMCRequest , {
 "remoteMCRequest" , "h245.remoteMCRequest" , FT_UINT32 , BASE_DEC , VALS ( h245_RemoteMCRequest_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_CertSelectionCriteria_item , {
 "Criteria" , "h245.Criteria_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_field , {
 "field" , "h245.field" , FT_OID , BASE_NONE , NULL , 0 , "OBJECT_IDENTIFIER" , HFILL }
 }
 , {
 & hf_h245_criteriaValue , {
 "value" , "h245.value" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1_65535" , HFILL }
 }
 , {
 & hf_h245_mcuNumber , {
 "mcuNumber" , "h245.mcuNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalNumber , {
 "terminalNumber" , "h245.terminalNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mCTerminalIDResponse , {
 "mCTerminalIDResponse" , "h245.mCTerminalIDResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalID , {
 "terminalID" , "h245.terminalID" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalIDResponse , {
 "terminalIDResponse" , "h245.terminalIDResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_conferenceIDResponse , {
 "conferenceIDResponse" , "h245.conferenceIDResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_conferenceID , {
 "conferenceID" , "h245.conferenceID" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_passwordResponse , {
 "passwordResponse" , "h245.passwordResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_password , {
 "password" , "h245.password" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalListResponse , {
 "terminalListResponse" , "h245.terminalListResponse" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_256_OF_TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_terminalListResponse_item , {
 "TerminalLabel" , "h245.TerminalLabel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoCommandReject , {
 "videoCommandReject" , "h245.videoCommandReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalDropReject , {
 "terminalDropReject" , "h245.terminalDropReject_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_makeMeChairResponse , {
 "makeMeChairResponse" , "h245.makeMeChairResponse" , FT_UINT32 , BASE_DEC , VALS ( h245_T_makeMeChairResponse_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_grantedChairToken , {
 "grantedChairToken" , "h245.grantedChairToken_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_deniedChairToken , {
 "deniedChairToken" , "h245.deniedChairToken_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_extensionAddressResponse , {
 "extensionAddressResponse" , "h245.extensionAddressResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_extensionAddress , {
 "extensionAddress" , "h245.extensionAddress" , FT_BYTES , BASE_NONE , NULL , 0 , "TerminalID" , HFILL }
 }
 , {
 & hf_h245_chairTokenOwnerResponse , {
 "chairTokenOwnerResponse" , "h245.chairTokenOwnerResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalCertificateResponse , {
 "terminalCertificateResponse" , "h245.terminalCertificateResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_certificateResponse , {
 "certificateResponse" , "h245.certificateResponse" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1_65535" , HFILL }
 }
 , {
 & hf_h245_broadcastMyLogicalChannelResponse , {
 "broadcastMyLogicalChannelResponse" , "h245.broadcastMyLogicalChannelResponse" , FT_UINT32 , BASE_DEC , VALS ( h245_T_broadcastMyLogicalChannelResponse_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_grantedBroadcastMyLogicalChannel , {
 "grantedBroadcastMyLogicalChannel" , "h245.grantedBroadcastMyLogicalChannel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_deniedBroadcastMyLogicalChannel , {
 "deniedBroadcastMyLogicalChannel" , "h245.deniedBroadcastMyLogicalChannel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_makeTerminalBroadcasterResponse , {
 "makeTerminalBroadcasterResponse" , "h245.makeTerminalBroadcasterResponse" , FT_UINT32 , BASE_DEC , VALS ( h245_T_makeTerminalBroadcasterResponse_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_grantedMakeTerminalBroadcaster , {
 "grantedMakeTerminalBroadcaster" , "h245.grantedMakeTerminalBroadcaster_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_deniedMakeTerminalBroadcaster , {
 "deniedMakeTerminalBroadcaster" , "h245.deniedMakeTerminalBroadcaster_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sendThisSourceResponse , {
 "sendThisSourceResponse" , "h245.sendThisSourceResponse" , FT_UINT32 , BASE_DEC , VALS ( h245_T_sendThisSourceResponse_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_grantedSendThisSource , {
 "grantedSendThisSource" , "h245.grantedSendThisSource_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_deniedSendThisSource , {
 "deniedSendThisSource" , "h245.deniedSendThisSource_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestAllTerminalIDsResponse , {
 "requestAllTerminalIDsResponse" , "h245.requestAllTerminalIDsResponse_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_remoteMCResponse , {
 "remoteMCResponse" , "h245.remoteMCResponse" , FT_UINT32 , BASE_DEC , VALS ( h245_RemoteMCResponse_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalInformation , {
 "terminalInformation" , "h245.terminalInformation" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_TerminalInformation" , HFILL }
 }
 , {
 & hf_h245_terminalInformation_item , {
 "TerminalInformation" , "h245.TerminalInformation_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_masterActivate , {
 "masterActivate" , "h245.masterActivate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_slaveActivate , {
 "slaveActivate" , "h245.slaveActivate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_deActivate , {
 "deActivate" , "h245.deActivate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_accept , {
 "accept" , "h245.accept_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_reject , {
 "reject" , "h245.reject" , FT_UINT32 , BASE_DEC , VALS ( h245_T_reject_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_functionNotSupportedFlag , {
 "functionNotSupported" , "h245.functionNotSupported_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_callInformationReq , {
 "callInformation" , "h245.callInformation_element" , FT_NONE , BASE_NONE , NULL , 0 , "CallInformationReq" , HFILL }
 }
 , {
 & hf_h245_maxNumberOfAdditionalConnections , {
 "maxNumberOfAdditionalConnections" , "h245.maxNumberOfAdditionalConnections" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65535" , HFILL }
 }
 , {
 & hf_h245_addConnectionReq , {
 "addConnection" , "h245.addConnection_element" , FT_NONE , BASE_NONE , NULL , 0 , "AddConnectionReq" , HFILL }
 }
 , {
 & hf_h245_dialingInformation , {
 "dialingInformation" , "h245.dialingInformation" , FT_UINT32 , BASE_DEC , VALS ( h245_DialingInformation_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_removeConnectionReq , {
 "removeConnection" , "h245.removeConnection_element" , FT_NONE , BASE_NONE , NULL , 0 , "RemoveConnectionReq" , HFILL }
 }
 , {
 & hf_h245_connectionIdentifier , {
 "connectionIdentifier" , "h245.connectionIdentifier_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_maximumHeaderIntervalReq , {
 "maximumHeaderInterval" , "h245.maximumHeaderInterval_element" , FT_NONE , BASE_NONE , NULL , 0 , "MaximumHeaderIntervalReq" , HFILL }
 }
 , {
 & hf_h245_requestType , {
 "requestType" , "h245.requestType" , FT_UINT32 , BASE_DEC , VALS ( h245_T_requestType_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_currentIntervalInformation , {
 "currentIntervalInformation" , "h245.currentIntervalInformation_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_requestedInterval , {
 "requestedInterval" , "h245.requestedInterval" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_callInformationResp , {
 "callInformation" , "h245.callInformation_element" , FT_NONE , BASE_NONE , NULL , 0 , "CallInformationResp" , HFILL }
 }
 , {
 & hf_h245_callAssociationNumber , {
 "callAssociationNumber" , "h245.callAssociationNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4294967295" , HFILL }
 }
 , {
 & hf_h245_addConnectionResp , {
 "addConnection" , "h245.addConnection_element" , FT_NONE , BASE_NONE , NULL , 0 , "AddConnectionResp" , HFILL }
 }
 , {
 & hf_h245_responseCode , {
 "responseCode" , "h245.responseCode" , FT_UINT32 , BASE_DEC , VALS ( h245_T_responseCode_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_accepted , {
 "accepted" , "h245.accepted_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rejected , {
 "rejected" , "h245.rejected" , FT_UINT32 , BASE_DEC , VALS ( h245_T_rejected_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_connectionsNotAvailable , {
 "connectionsNotAvailable" , "h245.connectionsNotAvailable_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_userRejected , {
 "userRejected" , "h245.userRejected_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_removeConnectionResp , {
 "removeConnection" , "h245.removeConnection_element" , FT_NONE , BASE_NONE , NULL , 0 , "RemoveConnectionResp" , HFILL }
 }
 , {
 & hf_h245_maximumHeaderIntervalResp , {
 "maximumHeaderInterval" , "h245.maximumHeaderInterval_element" , FT_NONE , BASE_NONE , NULL , 0 , "MaximumHeaderIntervalResp" , HFILL }
 }
 , {
 & hf_h245_currentInterval , {
 "currentInterval" , "h245.currentInterval" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_65535" , HFILL }
 }
 , {
 & hf_h245_crcDesired , {
 "crcDesired" , "h245.crcDesired_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_excessiveError , {
 "excessiveError" , "h245.excessiveError_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_differential , {
 "differential" , "h245.differential" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_65535_OF_DialingInformationNumber" , HFILL }
 }
 , {
 & hf_h245_differential_item , {
 "DialingInformationNumber" , "h245.DialingInformationNumber_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_infoNotAvailable , {
 "infoNotAvailable" , "h245.infoNotAvailable" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65535" , HFILL }
 }
 , {
 & hf_h245_networkAddressNum , {
 "networkAddress" , "h245.networkAddress" , FT_STRING , BASE_NONE , NULL , 0 , "NumericString_SIZE_0_40" , HFILL }
 }
 , {
 & hf_h245_subAddress , {
 "subAddress" , "h245.subAddress" , FT_STRING , BASE_NONE , NULL , 0 , "IA5String_SIZE_1_40" , HFILL }
 }
 , {
 & hf_h245_networkType , {
 "networkType" , "h245.networkType" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_255_OF_DialingInformationNetworkType" , HFILL }
 }
 , {
 & hf_h245_networkType_item , {
 "DialingInformationNetworkType" , "h245.DialingInformationNetworkType" , FT_UINT32 , BASE_DEC , VALS ( h245_DialingInformationNetworkType_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_n_isdn , {
 "n-isdn" , "h245.n_isdn_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_gstn , {
 "gstn" , "h245.gstn_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mobile , {
 "mobile" , "h245.mobile_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_channelTag , {
 "channelTag" , "h245.channelTag" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4294967295" , HFILL }
 }
 , {
 & hf_h245_sequenceNum , {
 "sequenceNumber" , "h245.sequenceNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4294967295" , HFILL }
 }
 , {
 & hf_h245_maximumBitRate , {
 "maximumBitRate" , "h245.maximumBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_rejectReason , {
 "rejectReason" , "h245.rejectReason" , FT_UINT32 , BASE_DEC , VALS ( h245_LogicalChannelRateRejectReason_vals ) , 0 , "LogicalChannelRateRejectReason" , HFILL }
 }
 , {
 & hf_h245_currentMaximumBitRate , {
 "currentMaximumBitRate" , "h245.currentMaximumBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "MaximumBitRate" , HFILL }
 }
 , {
 & hf_h245_undefinedReason , {
 "undefinedReason" , "h245.undefinedReason_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_insufficientResources , {
 "insufficientResources" , "h245.insufficientResources_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_specificRequest , {
 "specificRequest" , "h245.specificRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multiplexCapabilityBool , {
 "multiplexCapability" , "h245.multiplexCapability" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_capabilityTableEntryNumbers , {
 "capabilityTableEntryNumbers" , "h245.capabilityTableEntryNumbers" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_65535_OF_CapabilityTableEntryNumber" , HFILL }
 }
 , {
 & hf_h245_capabilityTableEntryNumbers_item , {
 "CapabilityTableEntryNumber" , "h245.CapabilityTableEntryNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_capabilityDescriptorNumbers , {
 "capabilityDescriptorNumbers" , "h245.capabilityDescriptorNumbers" , FT_UINT32 , BASE_DEC , NULL , 0 , "SET_SIZE_1_256_OF_CapabilityDescriptorNumber" , HFILL }
 }
 , {
 & hf_h245_capabilityDescriptorNumbers_item , {
 "CapabilityDescriptorNumber" , "h245.CapabilityDescriptorNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_genericRequestFlag , {
 "genericRequest" , "h245.genericRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptionSE , {
 "encryptionSE" , "h245.encryptionSE" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING" , HFILL }
 }
 , {
 & hf_h245_encryptionIVRequest , {
 "encryptionIVRequest" , "h245.encryptionIVRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptionAlgorithmID , {
 "encryptionAlgorithmID" , "h245.encryptionAlgorithmID_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h233AlgorithmIdentifier , {
 "h233AlgorithmIdentifier" , "h245.h233AlgorithmIdentifier" , FT_UINT32 , BASE_DEC , NULL , 0 , "SequenceNumber" , HFILL }
 }
 , {
 & hf_h245_associatedAlgorithm , {
 "associatedAlgorithm" , "h245.associatedAlgorithm_element" , FT_NONE , BASE_NONE , NULL , 0 , "NonStandardParameter" , HFILL }
 }
 , {
 & hf_h245_wholeMultiplex , {
 "wholeMultiplex" , "h245.wholeMultiplex_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_scope , {
 "scope" , "h245.scope" , FT_UINT32 , BASE_DEC , VALS ( h245_Scope_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_res_maximumBitRate , {
 "maximumBitRate" , "h245.maximumBitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_16777215" , HFILL }
 }
 , {
 & hf_h245_noRestriction , {
 "noRestriction" , "h245.noRestriction_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_restriction , {
 "restriction" , "h245.restriction" , FT_UINT32 , BASE_DEC , VALS ( h245_Restriction_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_disconnect , {
 "disconnect" , "h245.disconnect_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_gstnOptions , {
 "gstnOptions" , "h245.gstnOptions" , FT_UINT32 , BASE_DEC , VALS ( h245_T_gstnOptions_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_telephonyMode , {
 "telephonyMode" , "h245.telephonyMode_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v8bis , {
 "v8bis" , "h245.v8bis_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v34DSVD , {
 "v34DSVD" , "h245.v34DSVD_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v34DuplexFAX , {
 "v34DuplexFAX" , "h245.v34DuplexFAX_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v34H324 , {
 "v34H324" , "h245.v34H324_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_isdnOptions , {
 "isdnOptions" , "h245.isdnOptions" , FT_UINT32 , BASE_DEC , VALS ( h245_T_isdnOptions_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_v140 , {
 "v140" , "h245.v140_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalOnHold , {
 "terminalOnHold" , "h245.terminalOnHold_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelBroadcastMyLogicalChannel , {
 "cancelBroadcastMyLogicalChannel" , "h245.cancelBroadcastMyLogicalChannel" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_cancelMakeTerminalBroadcaster , {
 "cancelMakeTerminalBroadcaster" , "h245.cancelMakeTerminalBroadcaster_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelSendThisSource , {
 "cancelSendThisSource" , "h245.cancelSendThisSource_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_dropConference , {
 "dropConference" , "h245.dropConference_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_substituteConferenceIDCommand , {
 "substituteConferenceIDCommand" , "h245.substituteConferenceIDCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_conferenceIdentifier , {
 "conferenceIdentifier" , "h245.conferenceIdentifier" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_16" , HFILL }
 }
 , {
 & hf_h245_masterToSlave , {
 "masterToSlave" , "h245.masterToSlave_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_slaveToMaster , {
 "slaveToMaster" , "h245.slaveToMaster_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_mc_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_Mc_type_vals ) , 0 , "Mc_type" , HFILL }
 }
 , {
 & hf_h245_equaliseDelay , {
 "equaliseDelay" , "h245.equaliseDelay_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_zeroDelay , {
 "zeroDelay" , "h245.zeroDelay_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multipointModeCommand , {
 "multipointModeCommand" , "h245.multipointModeCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelMultipointModeCommand , {
 "cancelMultipointModeCommand" , "h245.cancelMultipointModeCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoFreezePicture , {
 "videoFreezePicture" , "h245.videoFreezePicture_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoFastUpdatePicture , {
 "videoFastUpdatePicture" , "h245.videoFastUpdatePicture_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoFastUpdateGOB , {
 "videoFastUpdateGOB" , "h245.videoFastUpdateGOB_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_firstGOB , {
 "firstGOB" , "h245.firstGOB" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_17" , HFILL }
 }
 , {
 & hf_h245_numberOfGOBs , {
 "numberOfGOBs" , "h245.numberOfGOBs" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_18" , HFILL }
 }
 , {
 & hf_h245_videoTemporalSpatialTradeOff , {
 "videoTemporalSpatialTradeOff" , "h245.videoTemporalSpatialTradeOff" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_31" , HFILL }
 }
 , {
 & hf_h245_videoSendSyncEveryGOB , {
 "videoSendSyncEveryGOB" , "h245.videoSendSyncEveryGOB_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoSendSyncEveryGOBCancel , {
 "videoSendSyncEveryGOBCancel" , "h245.videoSendSyncEveryGOBCancel_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoFastUpdateMB , {
 "videoFastUpdateMB" , "h245.videoFastUpdateMB_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_firstGOB_0_255 , {
 "firstGOB" , "h245.firstGOB" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_firstMB_1_8192 , {
 "firstMB" , "h245.firstMB" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_8192" , HFILL }
 }
 , {
 & hf_h245_numberOfMBs , {
 "numberOfMBs" , "h245.numberOfMBs" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_8192" , HFILL }
 }
 , {
 & hf_h245_maxH223MUXPDUsize , {
 "maxH223MUXPDUsize" , "h245.maxH223MUXPDUsize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65535" , HFILL }
 }
 , {
 & hf_h245_encryptionUpdate , {
 "encryptionUpdate" , "h245.encryptionUpdate_element" , FT_NONE , BASE_NONE , NULL , 0 , "EncryptionSync" , HFILL }
 }
 , {
 & hf_h245_encryptionUpdateRequest , {
 "encryptionUpdateRequest" , "h245.encryptionUpdateRequest_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_switchReceiveMediaOff , {
 "switchReceiveMediaOff" , "h245.switchReceiveMediaOff_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_switchReceiveMediaOn , {
 "switchReceiveMediaOn" , "h245.switchReceiveMediaOn_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_progressiveRefinementStart , {
 "progressiveRefinementStart" , "h245.progressiveRefinementStart_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_repeatCount , {
 "repeatCount" , "h245.repeatCount" , FT_UINT32 , BASE_DEC , VALS ( h245_T_repeatCount_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_doOneProgression , {
 "doOneProgression" , "h245.doOneProgression_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_doContinuousProgressions , {
 "doContinuousProgressions" , "h245.doContinuousProgressions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_doOneIndependentProgression , {
 "doOneIndependentProgression" , "h245.doOneIndependentProgression_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_doContinuousIndependentProgressions , {
 "doContinuousIndependentProgressions" , "h245.doContinuousIndependentProgressions_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_progressiveRefinementAbortOne , {
 "progressiveRefinementAbortOne" , "h245.progressiveRefinementAbortOne_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_progressiveRefinementAbortContinuous , {
 "progressiveRefinementAbortContinuous" , "h245.progressiveRefinementAbortContinuous_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoBadMBs , {
 "videoBadMBs" , "h245.videoBadMBs_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_firstMB , {
 "firstMB" , "h245.firstMB" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_9216" , HFILL }
 }
 , {
 & hf_h245_numberOfMBs1_1_9216 , {
 "numberOfMBs" , "h245.numberOfMBs" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_9216" , HFILL }
 }
 , {
 & hf_h245_temporalReference , {
 "temporalReference" , "h245.temporalReference" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_1023" , HFILL }
 }
 , {
 & hf_h245_lostPicture , {
 "lostPicture" , "h245.lostPicture" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_PictureReference" , HFILL }
 }
 , {
 & hf_h245_lostPicture_item , {
 "PictureReference" , "h245.PictureReference" , FT_UINT32 , BASE_DEC , VALS ( h245_PictureReference_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_lostPartialPicture , {
 "lostPartialPicture" , "h245.lostPartialPicture_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_pictureReference , {
 "pictureReference" , "h245.pictureReference" , FT_UINT32 , BASE_DEC , VALS ( h245_PictureReference_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_recoveryReferencePicture , {
 "recoveryReferencePicture" , "h245.recoveryReferencePicture" , FT_UINT32 , BASE_DEC , NULL , 0 , "SEQUENCE_OF_PictureReference" , HFILL }
 }
 , {
 & hf_h245_recoveryReferencePicture_item , {
 "PictureReference" , "h245.PictureReference" , FT_UINT32 , BASE_DEC , VALS ( h245_PictureReference_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptionUpdateCommand , {
 "encryptionUpdateCommand" , "h245.encryptionUpdateCommand_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptionUpdateAck , {
 "encryptionUpdateAck" , "h245.encryptionUpdateAck_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_direction , {
 "direction" , "h245.direction" , FT_UINT32 , BASE_DEC , VALS ( h245_EncryptionUpdateDirection_vals ) , 0 , "EncryptionUpdateDirection" , HFILL }
 }
 , {
 & hf_h245_secureChannel , {
 "secureChannel" , "h245.secureChannel" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_sharedSecret , {
 "sharedSecret" , "h245.sharedSecret" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_certProtectedKey , {
 "certProtectedKey" , "h245.certProtectedKey" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_keyProtectionMethod , {
 "keyProtectionMethod" , "h245.keyProtectionMethod_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_pictureNumber , {
 "pictureNumber" , "h245.pictureNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_1023" , HFILL }
 }
 , {
 & hf_h245_longTermPictureIndex , {
 "longTermPictureIndex" , "h245.longTermPictureIndex" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_h223ModeChange , {
 "h223ModeChange" , "h245.h223ModeChange" , FT_UINT32 , BASE_DEC , VALS ( h245_T_h223ModeChange_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_toLevel0 , {
 "toLevel0" , "h245.toLevel0_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_toLevel1 , {
 "toLevel1" , "h245.toLevel1_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_toLevel2 , {
 "toLevel2" , "h245.toLevel2_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_toLevel2withOptionalHeader , {
 "toLevel2withOptionalHeader" , "h245.toLevel2withOptionalHeader_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_h223AnnexADoubleFlag , {
 "h223AnnexADoubleFlag" , "h245.h223AnnexADoubleFlag" , FT_UINT32 , BASE_DEC , VALS ( h245_T_h223AnnexADoubleFlag_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_start , {
 "start" , "h245.start_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_stop , {
 "stop" , "h245.stop_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_bitRate , {
 "bitRate" , "h245.bitRate" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65535" , HFILL }
 }
 , {
 & hf_h245_bitRateLockedToPCRClock , {
 "bitRateLockedToPCRClock" , "h245.bitRateLockedToPCRClock" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_bitRateLockedToNetworkClock , {
 "bitRateLockedToNetworkClock" , "h245.bitRateLockedToNetworkClock" , FT_BOOLEAN , BASE_NONE , NULL , 0 , "BOOLEAN" , HFILL }
 }
 , {
 & hf_h245_cmd_aal , {
 "aal" , "h245.aal" , FT_UINT32 , BASE_DEC , VALS ( h245_Cmd_aal_vals ) , 0 , "Cmd_aal" , HFILL }
 }
 , {
 & hf_h245_cmd_aal1 , {
 "aal1" , "h245.aal1_element" , FT_NONE , BASE_NONE , NULL , 0 , "Cmd_aal1" , HFILL }
 }
 , {
 & hf_h245_cmd_clockRecovery , {
 "clockRecovery" , "h245.clockRecovery" , FT_UINT32 , BASE_DEC , VALS ( h245_Cmd_clockRecovery_vals ) , 0 , "Cmd_clockRecovery" , HFILL }
 }
 , {
 & hf_h245_nullClockRecoveryflag , {
 "nullClockRecovery" , "h245.nullClockRecovery_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_srtsClockRecovery , {
 "srtsClockRecovery" , "h245.srtsClockRecovery_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_adaptiveClockRecoveryFlag , {
 "adaptiveClockRecovery" , "h245.adaptiveClockRecovery_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cmd_errorCorrection , {
 "errorCorrection" , "h245.errorCorrection" , FT_UINT32 , BASE_DEC , VALS ( h245_Cmd_errorCorrection_vals ) , 0 , "Cmd_errorCorrection" , HFILL }
 }
 , {
 & hf_h245_nullErrorCorrectionFlag , {
 "nullErrorCorrection" , "h245.nullErrorCorrection_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_longInterleaverFlag , {
 "longInterleaver" , "h245.longInterleaver_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_shortInterleaverFlag , {
 "shortInterleaver" , "h245.shortInterleaver_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_errorCorrectionOnlyFlag , {
 "errorCorrectionOnly" , "h245.errorCorrectionOnly_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cmd_aal5 , {
 "aal5" , "h245.aal5_element" , FT_NONE , BASE_NONE , NULL , 0 , "Cmd_aal5" , HFILL }
 }
 , {
 & hf_h245_cmd_multiplex , {
 "multiplex" , "h245.multiplex" , FT_UINT32 , BASE_DEC , VALS ( h245_Cmd_multiplex_vals ) , 0 , "Cmd_multiplex" , HFILL }
 }
 , {
 & hf_h245_noMultiplex , {
 "noMultiplex" , "h245.noMultiplex_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_transportStream , {
 "transportStream" , "h245.transportStream_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_programStreamFlag , {
 "programStream" , "h245.programStream_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cmd_reverseParameters , {
 "reverseParameters" , "h245.reverseParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , "Cmd_reverseParameters" , HFILL }
 }
 , {
 & hf_h245_cmdr_multiplex , {
 "multiplex" , "h245.multiplex" , FT_UINT32 , BASE_DEC , VALS ( h245_CmdR_multiplex_vals ) , 0 , "CmdR_multiplex" , HFILL }
 }
 , {
 & hf_h245_sampleSize , {
 "sampleSize" , "h245.sampleSize" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_samplesPerFrame , {
 "samplesPerFrame" , "h245.samplesPerFrame" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_255" , HFILL }
 }
 , {
 & hf_h245_status , {
 "status" , "h245.status" , FT_UINT32 , BASE_DEC , VALS ( h245_T_status_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_synchronized , {
 "synchronized" , "h245.synchronized_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_reconfiguration , {
 "reconfiguration" , "h245.reconfiguration_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_fns_cause , {
 "cause" , "h245.cause" , FT_UINT32 , BASE_DEC , VALS ( h245_FunctionNotSupportedCause_vals ) , 0 , "FunctionNotSupportedCause" , HFILL }
 }
 , {
 & hf_h245_syntaxError , {
 "syntaxError" , "h245.syntaxError_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_semanticError , {
 "semanticError" , "h245.semanticError_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_unknownFunction , {
 "unknownFunction" , "h245.unknownFunction_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_returnedFunction , {
 "returnedFunction" , "h245.returnedFunction" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_sbeNumber , {
 "sbeNumber" , "h245.sbeNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_9" , HFILL }
 }
 , {
 & hf_h245_terminalNumberAssign , {
 "terminalNumberAssign" , "h245.terminalNumberAssign_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_terminalJoinedConference , {
 "terminalJoinedConference" , "h245.terminalJoinedConference_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_terminalLeftConference , {
 "terminalLeftConference" , "h245.terminalLeftConference_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_seenByAtLeastOneOther , {
 "seenByAtLeastOneOther" , "h245.seenByAtLeastOneOther_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelSeenByAtLeastOneOther , {
 "cancelSeenByAtLeastOneOther" , "h245.cancelSeenByAtLeastOneOther_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_seenByAll , {
 "seenByAll" , "h245.seenByAll_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelSeenByAll , {
 "cancelSeenByAll" , "h245.cancelSeenByAll_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_terminalYouAreSeeing , {
 "terminalYouAreSeeing" , "h245.terminalYouAreSeeing_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_requestForFloor , {
 "requestForFloor" , "h245.requestForFloor_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_withdrawChairToken , {
 "withdrawChairToken" , "h245.withdrawChairToken_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_floorRequested , {
 "floorRequested" , "h245.floorRequested_element" , FT_NONE , BASE_NONE , NULL , 0 , "TerminalLabel" , HFILL }
 }
 , {
 & hf_h245_terminalYouAreSeeingInSubPictureNumber , {
 "terminalYouAreSeeingInSubPictureNumber" , "h245.terminalYouAreSeeingInSubPictureNumber_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoIndicateCompose , {
 "videoIndicateCompose" , "h245.videoIndicateCompose_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_masterMCU , {
 "masterMCU" , "h245.masterMCU_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelMasterMCU , {
 "cancelMasterMCU" , "h245.cancelMasterMCU_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_subPictureNumber , {
 "subPictureNumber" , "h245.subPictureNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_compositionNumber , {
 "compositionNumber" , "h245.compositionNumber" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_mi_type , {
 "type" , "h245.type" , FT_UINT32 , BASE_DEC , VALS ( h245_Mi_type_vals ) , 0 , "Mi_type" , HFILL }
 }
 , {
 & hf_h245_logicalChannelActive , {
 "logicalChannelActive" , "h245.logicalChannelActive_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_logicalChannelInactive , {
 "logicalChannelInactive" , "h245.logicalChannelInactive_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multipointConference , {
 "multipointConference" , "h245.multipointConference_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelMultipointConference , {
 "cancelMultipointConference" , "h245.cancelMultipointConference_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multipointZeroComm , {
 "multipointZeroComm" , "h245.multipointZeroComm_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelMultipointZeroComm , {
 "cancelMultipointZeroComm" , "h245.cancelMultipointZeroComm_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_multipointSecondaryStatus , {
 "multipointSecondaryStatus" , "h245.multipointSecondaryStatus_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_cancelMultipointSecondaryStatus , {
 "cancelMultipointSecondaryStatus" , "h245.cancelMultipointSecondaryStatus_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoIndicateReadyToActivate , {
 "videoIndicateReadyToActivate" , "h245.videoIndicateReadyToActivate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_videoNotDecodedMBs , {
 "videoNotDecodedMBs" , "h245.videoNotDecodedMBs_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_temporalReference_0_255 , {
 "temporalReference" , "h245.temporalReference" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_255" , HFILL }
 }
 , {
 & hf_h245_estimatedReceivedJitterMantissa , {
 "estimatedReceivedJitterMantissa" , "h245.estimatedReceivedJitterMantissa" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_3" , HFILL }
 }
 , {
 & hf_h245_estimatedReceivedJitterExponent , {
 "estimatedReceivedJitterExponent" , "h245.estimatedReceivedJitterExponent" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_7" , HFILL }
 }
 , {
 & hf_h245_skippedFrameCount , {
 "skippedFrameCount" , "h245.skippedFrameCount" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_15" , HFILL }
 }
 , {
 & hf_h245_additionalDecoderBuffer , {
 "additionalDecoderBuffer" , "h245.additionalDecoderBuffer" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_262143" , HFILL }
 }
 , {
 & hf_h245_logicalChannelNumber1 , {
 "logicalChannelNumber1" , "h245.logicalChannelNumber1" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_logicalChannelNumber2 , {
 "logicalChannelNumber2" , "h245.logicalChannelNumber2" , FT_UINT32 , BASE_DEC , NULL , 0 , "LogicalChannelNumber" , HFILL }
 }
 , {
 & hf_h245_skew , {
 "skew" , "h245.skew" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4095" , HFILL }
 }
 , {
 & hf_h245_maximumSkew , {
 "maximumSkew" , "h245.maximumSkew" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4095" , HFILL }
 }
 , {
 & hf_h245_signalAddress , {
 "signalAddress" , "h245.signalAddress" , FT_UINT32 , BASE_DEC , VALS ( h245_TransportAddress_vals ) , 0 , "TransportAddress" , HFILL }
 }
 , {
 & hf_h245_vendor , {
 "vendor" , "h245.vendor" , FT_UINT32 , BASE_DEC , VALS ( h245_NonStandardIdentifier_vals ) , 0 , "NonStandardIdentifier" , HFILL }
 }
 , {
 & hf_h245_productNumber , {
 "productNumber" , "h245.productNumber" , FT_STRING , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1_256" , HFILL }
 }
 , {
 & hf_h245_versionNumber , {
 "versionNumber" , "h245.versionNumber" , FT_STRING , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1_256" , HFILL }
 }
 , {
 & hf_h245_ind_aal , {
 "aal" , "h245.aal" , FT_UINT32 , BASE_DEC , VALS ( h245_Ind_aal_vals ) , 0 , "Ind_aal" , HFILL }
 }
 , {
 & hf_h245_ind_aal1 , {
 "aal1" , "h245.aal1_element" , FT_NONE , BASE_NONE , NULL , 0 , "Ind_aal1" , HFILL }
 }
 , {
 & hf_h245_ind_clockRecovery , {
 "clockRecovery" , "h245.clockRecovery" , FT_UINT32 , BASE_DEC , VALS ( h245_Ind_clockRecovery_vals ) , 0 , "Ind_clockRecovery" , HFILL }
 }
 , {
 & hf_h245_ind_errorCorrection , {
 "errorCorrection" , "h245.errorCorrection" , FT_UINT32 , BASE_DEC , VALS ( h245_Ind_errorCorrection_vals ) , 0 , "Ind_errorCorrection" , HFILL }
 }
 , {
 & hf_h245_ind_aal5 , {
 "aal5" , "h245.aal5_element" , FT_NONE , BASE_NONE , NULL , 0 , "Ind_aal5" , HFILL }
 }
 , {
 & hf_h245_ind_multiplex , {
 "multiplex" , "h245.multiplex" , FT_UINT32 , BASE_DEC , VALS ( h245_Ind_multiplex_vals ) , 0 , "Ind_multiplex" , HFILL }
 }
 , {
 & hf_h245_ind_reverseParameters , {
 "reverseParameters" , "h245.reverseParameters_element" , FT_NONE , BASE_NONE , NULL , 0 , "Ind_reverseParameters" , HFILL }
 }
 , {
 & hf_h245_indr_multiplex , {
 "multiplex" , "h245.multiplex" , FT_UINT32 , BASE_DEC , VALS ( h245_IndR_multiplex_vals ) , 0 , "IndR_multiplex" , HFILL }
 }
 , {
 & hf_h245_iv8 , {
 "iv8" , "h245.iv8" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_iv16 , {
 "iv16" , "h245.iv16" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_iv , {
 "iv" , "h245.iv" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING" , HFILL }
 }
 , {
 & hf_h245_alphanumeric , {
 "alphanumeric" , "h245.alphanumeric" , FT_STRING , BASE_NONE , NULL , 0 , "GeneralString" , HFILL }
 }
 , {
 & hf_h245_userInputSupportIndication , {
 "userInputSupportIndication" , "h245.userInputSupportIndication" , FT_UINT32 , BASE_DEC , VALS ( h245_T_userInputSupportIndication_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_signal , {
 "signal" , "h245.signal_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_signalType , {
 "signalType" , "h245.signalType" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_duration , {
 "duration" , "h245.duration" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_1_65535" , HFILL }
 }
 , {
 & hf_h245_rtp , {
 "rtp" , "h245.rtp_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_timestamp , {
 "timestamp" , "h245.timestamp" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4294967295" , HFILL }
 }
 , {
 & hf_h245_expirationTime , {
 "expirationTime" , "h245.expirationTime" , FT_UINT32 , BASE_DEC , NULL , 0 , "INTEGER_0_4294967295" , HFILL }
 }
 , {
 & hf_h245_rtpPayloadIndication , {
 "rtpPayloadIndication" , "h245.rtpPayloadIndication_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_paramS , {
 "paramS" , "h245.paramS_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encryptedSignalType , {
 "encryptedSignalType" , "h245.encryptedSignalType" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING_SIZE_1" , HFILL }
 }
 , {
 & hf_h245_algorithmOID , {
 "algorithmOID" , "h245.algorithmOID" , FT_OID , BASE_NONE , NULL , 0 , "OBJECT_IDENTIFIER" , HFILL }
 }
 , {
 & hf_h245_signalUpdate , {
 "signalUpdate" , "h245.signalUpdate_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_si_rtp , {
 "rtp" , "h245.rtp_element" , FT_NONE , BASE_NONE , NULL , 0 , "Si_rtp" , HFILL }
 }
 , {
 & hf_h245_extendedAlphanumeric , {
 "extendedAlphanumeric" , "h245.extendedAlphanumeric_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_h245_encrypted , {
 "encrypted" , "h245.encrypted" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING" , HFILL }
 }
 , {
 & hf_h245_encryptedAlphanumeric , {
 "encryptedAlphanumeric" , "h245.encryptedAlphanumeric_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , # line 481 "../../asn1/h245/packet-h245-template.c" }
 ;
 static gint * ett [ ] = {
 & ett_h245 , & ett_h245_returnedFunction , # line 1 "../../asn1/h245/packet-h245-ettarr.c" & ett_h245_MultimediaSystemControlMessage , & ett_h245_RequestMessage , & ett_h245_ResponseMessage , & ett_h245_CommandMessage , & ett_h245_IndicationMessage , & ett_h245_GenericMessage , & ett_h245_T_messageContent , & ett_h245_NonStandardMessage , & ett_h245_NonStandardParameter , & ett_h245_NonStandardIdentifier , & ett_h245_H221NonStandardID , & ett_h245_MasterSlaveDetermination , & ett_h245_MasterSlaveDeterminationAck , & ett_h245_T_decision , & ett_h245_MasterSlaveDeterminationReject , & ett_h245_MasterSlaveDeterminationRejectCause , & ett_h245_MasterSlaveDeterminationRelease , & ett_h245_TerminalCapabilitySet , & ett_h245_SET_SIZE_1_256_OF_CapabilityTableEntry , & ett_h245_SET_SIZE_1_256_OF_CapabilityDescriptor , & ett_h245_SEQUENCE_OF_GenericInformation , & ett_h245_CapabilityTableEntry , & ett_h245_CapabilityDescriptor , & ett_h245_SET_SIZE_1_256_OF_AlternativeCapabilitySet , & ett_h245_AlternativeCapabilitySet , & ett_h245_TerminalCapabilitySetAck , & ett_h245_TerminalCapabilitySetReject , & ett_h245_TerminalCapabilitySetRejectCause , & ett_h245_T_tableEntryCapacityExceeded , & ett_h245_TerminalCapabilitySetRelease , & ett_h245_Capability , & ett_h245_T_h233EncryptionReceiveCapability , & ett_h245_H235SecurityCapability , & ett_h245_MultiplexCapability , & ett_h245_H222Capability , & ett_h245_SET_OF_VCCapability , & ett_h245_VCCapability , & ett_h245_T_aal1 , & ett_h245_T_aal5 , & ett_h245_T_availableBitRates , & ett_h245_Avb_type , & ett_h245_T_rangeOfBitRates , & ett_h245_T_aal1ViaGateway , & ett_h245_SET_SIZE_1_256_OF_Q2931Address , & ett_h245_H223Capability , & ett_h245_T_h223MultiplexTableCapability , & ett_h245_T_enhanced , & ett_h245_T_mobileOperationTransmitCapability , & ett_h245_T_mobileMultilinkFrameCapability , & ett_h245_H223AnnexCCapability , & ett_h245_V76Capability , & ett_h245_V75Capability , & ett_h245_H2250Capability , & ett_h245_T_mcCapability , & ett_h245_SEQUENCE_SIZE_1_256_OF_RedundancyEncodingCapability , & ett_h245_MediaPacketizationCapability , & ett_h245_SEQUENCE_SIZE_1_256_OF_RTPPayloadType , & ett_h245_RSVPParameters , & ett_h245_QOSMode , & ett_h245_ATMParameters , & ett_h245_ServicePriorityValue , & ett_h245_ServicePriority , & ett_h245_AuthorizationParameters , & ett_h245_QOSType , & ett_h245_QOSClass , & ett_h245_QOSDescriptor , & ett_h245_GenericTransportParameters , & ett_h245_QOSCapability , & ett_h245_MediaTransportType , & ett_h245_T_atm_AAL5_compressed , & ett_h245_MediaChannelCapability , & ett_h245_TransportCapability , & ett_h245_SEQUENCE_SIZE_1_256_OF_QOSCapability , & ett_h245_SEQUENCE_SIZE_1_256_OF_MediaChannelCapability , & ett_h245_RedundancyEncodingCapability , & ett_h245_SEQUENCE_SIZE_1_256_OF_CapabilityTableEntryNumber , & ett_h245_RedundancyEncodingMethod , & ett_h245_RTPH263VideoRedundancyEncoding , & ett_h245_T_frameToThreadMapping , & ett_h245_SEQUENCE_SIZE_1_256_OF_RTPH263VideoRedundancyFrameMapping , & ett_h245_T_containedThreads , & ett_h245_RTPH263VideoRedundancyFrameMapping , & ett_h245_T_frameSequence , & ett_h245_MultipointCapability , & ett_h245_SEQUENCE_OF_MediaDistributionCapability , & ett_h245_MediaDistributionCapability , & ett_h245_SEQUENCE_OF_DataApplicationCapability , & ett_h245_VideoCapability , & ett_h245_ExtendedVideoCapability , & ett_h245_SEQUENCE_OF_VideoCapability , & ett_h245_SEQUENCE_OF_GenericCapability , & ett_h245_H261VideoCapability , & ett_h245_H262VideoCapability , & ett_h245_H263VideoCapability , & ett_h245_EnhancementLayerInfo , & ett_h245_SET_SIZE_1_14_OF_EnhancementOptions , & ett_h245_SET_SIZE_1_14_OF_BEnhancementParameters , & ett_h245_BEnhancementParameters , & ett_h245_EnhancementOptions , & ett_h245_H263Options , & ett_h245_SET_SIZE_1_16_OF_CustomPictureClockFrequency , & ett_h245_SET_SIZE_1_16_OF_CustomPictureFormat , & ett_h245_SET_SIZE_1_16_OF_H263VideoModeCombos , & ett_h245_TransparencyParameters , & ett_h245_RefPictureSelection , & ett_h245_T_additionalPictureMemory , & ett_h245_T_videoBackChannelSend , & ett_h245_T_enhancedReferencePicSelect , & ett_h245_T_subPictureRemovalParameters , & ett_h245_CustomPictureClockFrequency , & ett_h245_CustomPictureFormat , & ett_h245_T_mPI , & ett_h245_T_customPCF , & ett_h245_T_customPCF_item , & ett_h245_T_pixelAspectInformation , & ett_h245_T_pixelAspectCode , & ett_h245_T_extendedPAR , & ett_h245_T_extendedPAR_item , & ett_h245_H263VideoModeCombos , & ett_h245_SET_SIZE_1_16_OF_H263ModeComboFlags , & ett_h245_H263ModeComboFlags , & ett_h245_H263Version3Options , & ett_h245_IS11172VideoCapability , & ett_h245_AudioCapability , & ett_h245_T_g7231 , & ett_h245_G729Extensions , & ett_h245_G7231AnnexCCapability , & ett_h245_G723AnnexCAudioMode , & ett_h245_IS11172AudioCapability , & ett_h245_IS13818AudioCapability , & ett_h245_GSMAudioCapability , & ett_h245_VBDCapability , & ett_h245_DataApplicationCapability , & ett_h245_Application , & ett_h245_T_t84 , & ett_h245_Nlpid , & ett_h245_T_t38fax , & ett_h245_DataProtocolCapability , & ett_h245_T_v76wCompression , & ett_h245_CompressionType , & ett_h245_V42bis , & ett_h245_T84Profile , & ett_h245_T_t84Restricted , & ett_h245_T38FaxProfile , & ett_h245_T38FaxRateManagement , & ett_h245_T38FaxUdpOptions , & ett_h245_T_t38FaxUdpEC , & ett_h245_T38FaxTcpOptions , & ett_h245_EncryptionAuthenticationAndIntegrity , & ett_h245_EncryptionCapability , & ett_h245_MediaEncryptionAlgorithm , & ett_h245_AuthenticationCapability , & ett_h245_IntegrityCapability , & ett_h245_UserInputCapability , & ett_h245_SEQUENCE_SIZE_1_16_OF_NonStandardParameter , & ett_h245_ConferenceCapability , & ett_h245_SEQUENCE_OF_NonStandardParameter , & ett_h245_GenericCapability , & ett_h245_T_collapsing , & ett_h245_T_nonCollapsing , & ett_h245_CapabilityIdentifier , & ett_h245_GenericParameter , & ett_h245_SEQUENCE_OF_ParameterIdentifier , & ett_h245_ParameterIdentifier , & ett_h245_ParameterValue , & ett_h245_SEQUENCE_OF_GenericParameter , & ett_h245_MultiplexedStreamCapability , & ett_h245_MultiplexFormat , & ett_h245_AudioTelephonyEventCapability , & ett_h245_AudioToneCapability , & ett_h245_NoPTAudioTelephonyEventCapability , & ett_h245_NoPTAudioToneCapability , & ett_h245_MultiplePayloadStreamCapability , & ett_h245_DepFECCapability , & ett_h245_FECC_rfc2733 , & ett_h245_T_separateStreamBool , & ett_h245_FECCapability , & ett_h245_Rfc2733Format , & ett_h245_OpenLogicalChannel , & ett_h245_T_forwardLogicalChannelParameters , & ett_h245_OLC_forw_multiplexParameters , & ett_h245_OLC_reverseLogicalChannelParameters , & ett_h245_OLC_rev_multiplexParameters , & ett_h245_NetworkAccessParameters , & ett_h245_T_distribution , & ett_h245_T_networkAddress , & ett_h245_T_t120SetupProcedure , & ett_h245_Q2931Address , & ett_h245_T_address , & ett_h245_V75Parameters , & ett_h245_DataType , & ett_h245_H235Media , & ett_h245_T_mediaType , & ett_h245_MultiplexedStreamParameter , & ett_h245_H222LogicalChannelParameters , & ett_h245_H223LogicalChannelParameters , & ett_h245_T_adaptationLayerType , & ett_h245_Al3 , & ett_h245_H223AL1MParameters , & ett_h245_T_transferMode , & ett_h245_AL1HeaderFEC , & ett_h245_AL1CrcLength , & ett_h245_ArqType , & ett_h245_H223AL2MParameters , & ett_h245_AL2HeaderFEC , & ett_h245_H223AL3MParameters , & ett_h245_T_headerFormat , & ett_h245_AL3CrcLength , & ett_h245_H223AnnexCArqParameters , & ett_h245_T_numberOfRetransmissions , & ett_h245_V76LogicalChannelParameters , & ett_h245_T_suspendResume , & ett_h245_V76LCP_mode , & ett_h245_T_eRM , & ett_h245_T_recovery , & ett_h245_V76HDLCParameters , & ett_h245_CRCLength , & ett_h245_H2250LogicalChannelParameters , & ett_h245_T_mediaPacketization , & ett_h245_RTPPayloadType , & ett_h245_T_payloadDescriptor , & ett_h245_RedundancyEncoding , & ett_h245_T_rtpRedundancyEncoding , & ett_h245_SEQUENCE_OF_RedundancyEncodingElement , & ett_h245_RedundancyEncodingElement , & ett_h245_MultiplePayloadStream , & ett_h245_SEQUENCE_OF_MultiplePayloadStreamElement , & ett_h245_MultiplePayloadStreamElement , & ett_h245_DepFECData , & ett_h245_RFC2733Data , & ett_h245_FECdata_mode , & ett_h245_DepSeparateStream , & ett_h245_T_differentPort , & ett_h245_T_samePort , & ett_h245_FECData , & ett_h245_T_rfc2733 , & ett_h245_T_pktMode , & ett_h245_T_mode_rfc2733sameport , & ett_h245_T_mode_rfc2733diffport , & ett_h245_TransportAddress , & ett_h245_UnicastAddress , & ett_h245_T_iPAddress , & ett_h245_T_iPXAddress , & ett_h245_T_iP6Address , & ett_h245_T_iPSourceRouteAddress , & ett_h245_T_routing , & ett_h245_T_route , & ett_h245_MulticastAddress , & ett_h245_MIPAddress , & ett_h245_MIP6Address , & ett_h245_EncryptionSync , & ett_h245_SEQUENCE_SIZE_1_256_OF_EscrowData , & ett_h245_EscrowData , & ett_h245_OpenLogicalChannelAck , & ett_h245_OLC_ack_reverseLogicalChannelParameters , & ett_h245_T_olc_ack_multiplexParameters , & ett_h245_T_forwardMultiplexAckParameters , & ett_h245_OpenLogicalChannelReject , & ett_h245_OpenLogicalChannelRejectCause , & ett_h245_OpenLogicalChannelConfirm , & ett_h245_H2250LogicalChannelAckParameters , & ett_h245_CloseLogicalChannel , & ett_h245_T_cLC_source , & ett_h245_Clc_reason , & ett_h245_CloseLogicalChannelAck , & ett_h245_RequestChannelClose , & ett_h245_T_reason , & ett_h245_RequestChannelCloseAck , & ett_h245_RequestChannelCloseReject , & ett_h245_RequestChannelCloseRejectCause , & ett_h245_RequestChannelCloseRelease , & ett_h245_MultiplexEntrySend , & ett_h245_SET_SIZE_1_15_OF_MultiplexEntryDescriptor , & ett_h245_MultiplexEntryDescriptor , & ett_h245_T_elementList , & ett_h245_MultiplexElement , & ett_h245_Me_type , & ett_h245_T_subElementList , & ett_h245_ME_repeatCount , & ett_h245_MultiplexEntrySendAck , & ett_h245_SET_SIZE_1_15_OF_MultiplexTableEntryNumber , & ett_h245_MultiplexEntrySendReject , & ett_h245_SET_SIZE_1_15_OF_MultiplexEntryRejectionDescriptions , & ett_h245_MultiplexEntryRejectionDescriptions , & ett_h245_MultiplexEntryRejectionDescriptionsCause , & ett_h245_MultiplexEntrySendRelease , & ett_h245_RequestMultiplexEntry , & ett_h245_RequestMultiplexEntryAck , & ett_h245_RequestMultiplexEntryReject , & ett_h245_SET_SIZE_1_15_OF_RequestMultiplexEntryRejectionDescriptions , & ett_h245_RequestMultiplexEntryRejectionDescriptions , & ett_h245_RequestMultiplexEntryRejectionDescriptionsCause , & ett_h245_RequestMultiplexEntryRelease , & ett_h245_RequestMode , & ett_h245_SEQUENCE_SIZE_1_256_OF_ModeDescription , & ett_h245_RequestModeAck , & ett_h245_Req_mode_ack_response , & ett_h245_RequestModeReject , & ett_h245_RequestModeRejectCause , & ett_h245_RequestModeRelease , & ett_h245_ModeDescription , & ett_h245_ModeElementType , & ett_h245_ModeElement , & ett_h245_H235Mode , & ett_h245_T_mediaMode , & ett_h245_MultiplexedStreamModeParameters , & ett_h245_RedundancyEncodingDTMode , & ett_h245_SEQUENCE_OF_RedundancyEncodingDTModeElement , & ett_h245_RedundancyEncodingDTModeElement , & ett_h245_Re_type , & ett_h245_MultiplePayloadStreamMode , & ett_h245_SEQUENCE_OF_MultiplePayloadStreamElementMode , & ett_h245_MultiplePayloadStreamElementMode , & ett_h245_DepFECMode , & ett_h245_T_rfc2733Mode , & ett_h245_FEC_mode , & ett_h245_FECMode , & ett_h245_H223ModeParameters , & ett_h245_AdaptationLayerType , & ett_h245_V76ModeParameters , & ett_h245_H2250ModeParameters , & ett_h245_RedundancyEncodingMode , & ett_h245_T_secondaryEncodingMode , & ett_h245_VideoMode , & ett_h245_H261VideoMode , & ett_h245_H261Resolution , & ett_h245_H262VideoMode , & ett_h245_T_profileAndLevel , & ett_h245_H263VideoMode , & ett_h245_H263Resolution , & ett_h245_IS11172VideoMode , & ett_h245_AudioMode , & ett_h245_Mode_g7231 , & ett_h245_IS11172AudioMode , & ett_h245_T_audioLayer , & ett_h245_T_audioSampling , & ett_h245_IS11172_multichannelType , & ett_h245_IS13818AudioMode , & ett_h245_IS13818AudioLayer , & ett_h245_IS13818AudioSampling , & ett_h245_IS13818MultichannelType , & ett_h245_G7231AnnexCMode , & ett_h245_VBDMode , & ett_h245_DataMode , & ett_h245_DataModeApplication , & ett_h245_T38faxApp , & ett_h245_EncryptionMode , & ett_h245_RoundTripDelayRequest , & ett_h245_RoundTripDelayResponse , & ett_h245_MaintenanceLoopRequest , & ett_h245_Mlr_type , & ett_h245_MaintenanceLoopAck , & ett_h245_Mla_type , & ett_h245_MaintenanceLoopReject , & ett_h245_Mlrej_type , & ett_h245_MaintenanceLoopRejectCause , & ett_h245_MaintenanceLoopOffCommand , & ett_h245_CommunicationModeCommand , & ett_h245_SET_SIZE_1_256_OF_CommunicationModeTableEntry , & ett_h245_CommunicationModeRequest , & ett_h245_CommunicationModeResponse , & ett_h245_CommunicationModeTableEntry , & ett_h245_T_entryDataType , & ett_h245_ConferenceRequest , & ett_h245_T_requestTerminalCertificate , & ett_h245_CertSelectionCriteria , & ett_h245_Criteria , & ett_h245_TerminalLabel , & ett_h245_ConferenceResponse , & ett_h245_T_mCTerminalIDResponse , & ett_h245_T_terminalIDResponse , & ett_h245_T_conferenceIDResponse , & ett_h245_T_passwordResponse , & ett_h245_SET_SIZE_1_256_OF_TerminalLabel , & ett_h245_T_makeMeChairResponse , & ett_h245_T_extensionAddressResponse , & ett_h245_T_chairTokenOwnerResponse , & ett_h245_T_terminalCertificateResponse , & ett_h245_T_broadcastMyLogicalChannelResponse , & ett_h245_T_makeTerminalBroadcasterResponse , & ett_h245_T_sendThisSourceResponse , & ett_h245_RequestAllTerminalIDsResponse , & ett_h245_SEQUENCE_OF_TerminalInformation , & ett_h245_TerminalInformation , & ett_h245_RemoteMCRequest , & ett_h245_RemoteMCResponse , & ett_h245_T_reject , & ett_h245_MultilinkRequest , & ett_h245_CallInformationReq , & ett_h245_AddConnectionReq , & ett_h245_RemoveConnectionReq , & ett_h245_MaximumHeaderIntervalReq , & ett_h245_T_requestType , & ett_h245_MultilinkResponse , & ett_h245_CallInformationResp , & ett_h245_AddConnectionResp , & ett_h245_T_responseCode , & ett_h245_T_rejected , & ett_h245_RemoveConnectionResp , & ett_h245_MaximumHeaderIntervalResp , & ett_h245_MultilinkIndication , & ett_h245_T_crcDesired , & ett_h245_T_excessiveError , & ett_h245_DialingInformation , & ett_h245_SET_SIZE_1_65535_OF_DialingInformationNumber , & ett_h245_DialingInformationNumber , & ett_h245_SET_SIZE_1_255_OF_DialingInformationNetworkType , & ett_h245_DialingInformationNetworkType , & ett_h245_ConnectionIdentifier , & ett_h245_LogicalChannelRateRequest , & ett_h245_LogicalChannelRateAcknowledge , & ett_h245_LogicalChannelRateReject , & ett_h245_LogicalChannelRateRejectReason , & ett_h245_LogicalChannelRateRelease , & ett_h245_SendTerminalCapabilitySet , & ett_h245_T_specificRequest , & ett_h245_SET_SIZE_1_65535_OF_CapabilityTableEntryNumber , & ett_h245_SET_SIZE_1_256_OF_CapabilityDescriptorNumber , & ett_h245_EncryptionCommand , & ett_h245_T_encryptionAlgorithmID , & ett_h245_FlowControlCommand , & ett_h245_Scope , & ett_h245_Restriction , & ett_h245_EndSessionCommand , & ett_h245_T_gstnOptions , & ett_h245_T_isdnOptions , & ett_h245_ConferenceCommand , & ett_h245_SubstituteConferenceIDCommand , & ett_h245_EncryptionUpdateDirection , & ett_h245_MiscellaneousCommand , & ett_h245_Mc_type , & ett_h245_T_videoFastUpdateGOB , & ett_h245_T_videoFastUpdateMB , & ett_h245_T_progressiveRefinementStart , & ett_h245_T_repeatCount , & ett_h245_T_videoBadMBs , & ett_h245_SEQUENCE_OF_PictureReference , & ett_h245_T_lostPartialPicture , & ett_h245_T_encryptionUpdateCommand , & ett_h245_T_encryptionUpdateAck , & ett_h245_KeyProtectionMethod , & ett_h245_EncryptionUpdateRequest , & ett_h245_PictureReference , & ett_h245_H223MultiplexReconfiguration , & ett_h245_T_h223ModeChange , & ett_h245_T_h223AnnexADoubleFlag , & ett_h245_NewATMVCCommand , & ett_h245_Cmd_aal , & ett_h245_Cmd_aal1 , & ett_h245_Cmd_clockRecovery , & ett_h245_Cmd_errorCorrection , & ett_h245_Cmd_aal5 , & ett_h245_Cmd_multiplex , & ett_h245_Cmd_reverseParameters , & ett_h245_CmdR_multiplex , & ett_h245_MobileMultilinkReconfigurationCommand , & ett_h245_T_status , & ett_h245_FunctionNotUnderstood , & ett_h245_FunctionNotSupported , & ett_h245_FunctionNotSupportedCause , & ett_h245_ConferenceIndication , & ett_h245_TerminalYouAreSeeingInSubPictureNumber , & ett_h245_VideoIndicateCompose , & ett_h245_MiscellaneousIndication , & ett_h245_Mi_type , & ett_h245_T_videoNotDecodedMBs , & ett_h245_JitterIndication , & ett_h245_H223SkewIndication , & ett_h245_H2250MaximumSkewIndication , & ett_h245_MCLocationIndication , & ett_h245_VendorIdentification , & ett_h245_NewATMVCIndication , & ett_h245_Ind_aal , & ett_h245_Ind_aal1 , & ett_h245_Ind_clockRecovery , & ett_h245_Ind_errorCorrection , & ett_h245_Ind_aal5 , & ett_h245_Ind_multiplex , & ett_h245_Ind_reverseParameters , & ett_h245_IndR_multiplex , & ett_h245_Params , & ett_h245_UserInputIndication , & ett_h245_T_userInputSupportIndication , & ett_h245_T_signal , & ett_h245_T_rtp , & ett_h245_T_signalUpdate , & ett_h245_Si_rtp , & ett_h245_T_extendedAlphanumeric , & ett_h245_EncryptedAlphanumeric , & ett_h245_FlowControlIndication , & ett_h245_MobileMultilinkReconfigurationIndication , # line 488 "../../asn1/h245/packet-h245-template.c" }
 ;
 module_t * h245_module ;
 proto_h245 = proto_register_protocol ( PNAME , PSNAME , PFNAME ) ;
 register_init_routine ( h245_init ) ;
 proto_register_field_array ( proto_h245 , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 h245_module = prefs_register_protocol ( proto_h245 , NULL ) ;
 prefs_register_bool_preference ( h245_module , "reassembly" , "Reassemble H.245 messages spanning multiple TCP segments" , "Whether the H.245 dissector should reassemble messages spanning multiple TCP segments." " To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings." , & h245_reassembly ) ;
 prefs_register_bool_preference ( h245_module , "shorttypes" , "Show short message types" , "Whether the dissector should show short names or the long names from the standard" , & h245_shorttypes ) ;
 register_dissector ( "h245dg" , dissect_h245_h245 , proto_h245 ) ;
 register_dissector ( "h245" , dissect_h245 , proto_h245 ) ;
 nsp_object_dissector_table = register_dissector_table ( "h245.nsp.object" , "H.245 NonStandardParameter (object)" , FT_STRING , BASE_NONE ) ;
 nsp_h221_dissector_table = register_dissector_table ( "h245.nsp.h221" , "H.245 NonStandardParameter (h221)" , FT_UINT32 , BASE_HEX ) ;
 gef_name_dissector_table = register_dissector_table ( "h245.gef.name" , "H.245 Generic Extensible Framework (names)" , FT_STRING , BASE_NONE ) ;
 gef_content_dissector_table = register_dissector_table ( "h245.gef.content" , "H.245 Generic Extensible Framework" , FT_STRING , BASE_NONE ) ;
 h245_tap = register_tap ( "h245" ) ;
 h245dg_tap = register_tap ( "h245dg" ) ;
 oid_add_from_string ( "h239ControlCapability" , "0.0.8.239.1.1" ) ;
 oid_add_from_string ( "h239ExtendedVideoCapability" , "0.0.8.239.1.2" ) ;
 oid_add_from_string ( "generic-message" , "0.0.8.239.2" ) ;
 oid_add_from_string ( "h245 version 3" , "0.0.8.245.0.3" ) ;
 oid_add_from_string ( "h245 version 4" , "0.0.8.245.0.4" ) ;
 oid_add_from_string ( "h245 version 5" , "0.0.8.245.0.5" ) ;
 oid_add_from_string ( "h245 version 6" , "0.0.8.245.0.6" ) ;
 oid_add_from_string ( "h245 version 7" , "0.0.8.245.0.7" ) ;
 oid_add_from_string ( "h245 version 8" , "0.0.8.245.0.8" ) ;
 oid_add_from_string ( "h245 version 9" , "0.0.8.245.0.9" ) ;
 oid_add_from_string ( "h245 version 10" , "0.0.8.245.0.10" ) ;
 oid_add_from_string ( "h245 version 11" , "0.0.8.245.0.11" ) ;
 oid_add_from_string ( "h245 version 12" , "0.0.8.245.0.12" ) ;
 oid_add_from_string ( "h245 version 13" , "0.0.8.245.0.13" ) ;
 oid_add_from_string ( "ISO/IEC 14496-2 MPEG-4 video" , "0.0.8.245.1.0.0" ) ;
 oid_add_from_string ( "ISO/IEC 14496-3 MPEG-4 audio" , "0.0.8.245.1.1.0" ) ;
 oid_add_from_string ( "AMR" , "0.0.8.245.1.1.1" ) ;
 oid_add_from_string ( "acelp" , "0.0.8.245.1.1.2" ) ;
 oid_add_from_string ( "us1" , "0.0.8.245.1.1.3" ) ;
 oid_add_from_string ( "is127evrc" , "0.0.8.245.1.1.4" ) ;
 oid_add_from_string ( "ISO/IEC 13818-7" , "0.0.8.245.1.1.5" ) ;
 oid_add_from_string ( "rfc3389" , "0.0.8.245.1.1.6" ) ;
 oid_add_from_string ( "L-16" , "0.0.8.245.1.1.7" ) ;
 oid_add_from_string ( "bounded-audio-stream" , "0.0.8.245.1.1.8" ) ;
 oid_add_from_string ( "AMR-NB" , "0.0.8.245.1.1.9" ) ;
 oid_add_from_string ( "AMR-WB" , "0.0.8.245.1.1.10" ) ;
 oid_add_from_string ( "ilbc" , "0.0.8.245.1.1.11" ) ;
 oid_add_from_string ( "ISO/IEC 14496-1" , "0.0.8.245.1.2.0" ) ;
 oid_add_from_string ( "Nx64" , "0.0.8.245.1.2.1" ) ;
 oid_add_from_string ( "logical-channel-bit-ratemanagement" , "0.0.8.245.1.3.0" ) ;
 oid_add_from_string ( "h264 generic-capabilities" , "0.0.8.241.0.0.1" ) ;
 oid_add_from_string ( "iPpacketization_h241AnnexA(single NAL unit mode)" , "0.0.8.241.0.0.0.0" ) ;
 oid_add_from_string ( "iPpacketization_RFC3984NonInterleaved" , "0.0.8.241.0.0.0.1" ) ;
 oid_add_from_string ( "iPpacketization_RFC3984Interleaved" , "0.0.8.241.0.0.0.2" ) ;
 }