/*! VideomasterHD_SDP.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : 

  Company : DELTACAST

  Author  : lr                             Date: 2019/02/13

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_SDP_H_
#define _VIDEOMASTERHD_SDP_H_

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_SDP
*/

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_SDP
*/

/*_ VHD_SDP_DESCRIPTION_TYPE _____________________________________*/
/*!
   Summary
   VideoMaster supported SDP description types
   Description
   The VHD_SDP_DESCRIPTION_TYPE enumeration lists all the
   supported SDP description types a user can interact with.
   
   See Also
   <link VHD_AddSDPDescription, VHD_RemoveSDPDescription,
   VHD_GetNbSDPDescriptions, VHD_GetSDPField, VHD_SetSDPField,
   VHD_AddSDPField, VHD_RemoveSDPField, VHD_GetNbSDPFields>
*/
typedef enum _VHD_SDP_DESCRIPTION_TYPE
{
   VHD_SDP_DESCRIPTION_TYPE_SESSION,   /*! SDP session description block type */
   VHD_SDP_DESCRIPTION_TYPE_TIME,      /*! SDP time description block type */
   VHD_SDP_DESCRIPTION_TYPE_MEDIA,     /*! SDP media description block type */
   NB_VHD_SDP_DESCRIPTION_TYPE
} VHD_SDP_DESCRIPTION_TYPE;

/*_ VHD_SDP_SESSION_FIELD _____________________________________*/
/*!
   Summary
   VideoMaster supported SDP session fields
   Description
   The VHD_SDP_SESSION_FIELD enumeration lists all the
   supported SDP session fields a user can interact with.
   
   See Also
   <link VHD_GetSDPField, VHD_SetSDPField,VHD_AddSDPField,
   VHD_RemoveSDPField, VHD_GetNbSDPFields>
*/
typedef enum _VHD_SDP_SESSION_FIELD
{
   VHD_SDP_SESSION_FIELD_VERSION,                  /*! SDP version field (session description block) */    
   VHD_SDP_SESSION_FIELD_ORIGINATOR,               /*! SDP originator field (session description block) */
   VHD_SDP_SESSION_FIELD_NAME,                     /*! SDP name field (session description block) */
   VHD_SDP_SESSION_FIELD_INFORMATION,              /*! SDP information field (session description block) */
   VHD_SDP_SESSION_FIELD_URI,                      /*! SDP URI field (session description block) */
   VHD_SDP_SESSION_FIELD_EMAIL_ADDRESS,            /*! SDP email address field (session description block) */
   VHD_SDP_SESSION_FIELD_PHONE_NUMBER,             /*! SDP phone number field (session description block) */
   VHD_SDP_SESSION_FIELD_CONNECTION_INFORMATION,   /*! SDP connection information field (session description block) */
   VHD_SDP_SESSION_FIELD_BANDWIDTH_INFORMATION,    /*! SDP bandwidth information field (session description block) */
   VHD_SDP_SESSION_FIELD_TIME_ZONE,                /*! SDP time zone field (session description block) */
   VHD_SDP_SESSION_FIELD_ENCRIPTION_KEY,           /*! SDP encryption key field (session description block) */
   VHD_SDP_SESSION_FIELD_ATTRIBUTE,                /*! SDP attribute field (session description block) */
   NB_VHD_SDP_SESSION_FIELD
} VHD_SDP_SESSION_FIELD;

/*_ VHD_SDP_TIME_FIELD ______________________________________*/
/*!
   Summary
   VideoMaster supported SDP time fields
   Description
   The VHD_SDP_TIME_FIELD enumeration lists all the
   supported SDP time fields a user can interact with.

   See Also
   <link VHD_GetSDPField, VHD_SetSDPField,VHD_AddSDPField,
   VHD_RemoveSDPField, VHD_GetNbSDPFields>
*/
typedef enum _VHD_SDP_TIME_FIELD
{
   VHD_SDP_TIME_FIELD_TIME_ACTIVE,  /*! SDP time active field (time description block) */
   VHD_SDP_TIME_FIELD_REPEAT_TIME,  /*! SDP repeat time field (time description block) */
   NB_VHD_SDP_TIME_FIELD
} VHD_SDP_TIME_FIELD;

/*_ VHD_SDP_MEDIA_FIELD ___________________________________________*/
/*!
   Summary
   VideoMaster supported SDP media fields
   Description
   The VHD_SDP_MEDIA_FIELD enumeration lists all the
   supported SDP media fields a user can interact with.

   See Also
   <link VHD_GetSDPField, VHD_SetSDPField,VHD_AddSDPField,
   VHD_RemoveSDPField, VHD_GetNbSDPFields>
*/
typedef enum _VHD_SDP_MEDIA_FIELD
{
   VHD_SDP_MEDIA_FIELD_NAME,                    /*! SDP name field (media description block) */
   VHD_SDP_MEDIA_FIELD_INFORMATION,             /*! SDP information field (media description block) */
   VHD_SDP_MEDIA_FIELD_CONNECTION_INFORMATION,  /*! SDP connection information field (media description block) */
   VHD_SDP_MEDIA_FIELD_BANDWIDTH_INFORMATION,   /*! SDP bandwidth information field (media description block) */
   VHD_SDP_MEDIA_FIELD_ENCRIPTION_KEY,          /*! SDP encryption key field (media description block) */
   VHD_SDP_MEDIA_FIELD_ATTRIBUTE,               /*! SDP attribute field (media description block) */
   NB_VHD_SDP_MEDIA_FIELD
} VHD_SDP_MEDIA_FIELD;

/*_ VHD_SDP_MEDIA_FIELD ___________________________________________*/
/*!
   Summary
   VideoMaster supported SDP media fields
   Description
   The VHD_SDP_MEDIA_FIELD enumeration lists all the
   supported SDP media fields a user can interact with.

   See Also
   <link VHD_GetSDPField, VHD_SetSDPField,VHD_AddSDPField,
   VHD_RemoveSDPField, VHD_GetNbSDPFields>
*/
typedef enum _VHD_SDP_ST2110_21_SENDER_TYPE
{
   VHD_SDP_ST2110_21_SENDER_TYPE_NARROW,        /*! Narrow sender type */
   VHD_SDP_ST2110_21_SENDER_TYPE_NARROW_LINEAR, /*! Narrow-linear sender type */
   VHD_SDP_ST2110_21_SENDER_TYPE_WIDE,          /*! Wide sender type */
   NB_VHD_SDP_ST2110_21_SENDER_TYPE,
} VHD_SDP_ST2110_21_SENDER_TYPE;

/*_ VHD_SDP_STREAM_PROPERTY ___________________________________________*/
/*!
   Summary
   VideoMaster supported SDP stream properties
   Description
   The VHD_SDP_STREAM_PROPERTY enumeration lists all the
   supported SDP stream properties a user can interact with.

   See Also
   <link VHD_GetSDPStreamProperty, VHD_SetSDPStreamProperty>
*/
typedef enum _VHD_SDP_STREAM_PROPERTY
{
   VHD_SDP_STREAM_PROPERTY_SOURCE_IP_ADDRESS,                  /*! Session source IP address */
   VHD_SDP_STREAM_PROPERTY_DESTINATION_IP_ADDRESS,             /*! Session destination IP address */
   VHD_SDP_STREAM_PROPERTY_START_TIME,                         /*! Time at which the session starts being active */
   VHD_SDP_STREAM_PROPERTY_END_TIME,                           /*! Time at which the session stops being active */
   VHD_SDP_STREAM_PROPERTY_REF_CLOCK_PTP_IDENTITY_MSB,         /*! PTP identity (32 most significant bits) */
   VHD_SDP_STREAM_PROPERTY_REF_CLOCK_PTP_IDENTITY_LSB,         /*! PTP identity (32 least significant bits) */
   VHD_SDP_STREAM_PROPERTY_REF_CLOCK_PTP_DOMAIN,               /*! PTP domain */
   VHD_SDP_STREAM_PROPERTY_REF_CLOCK_PTP_IS_TRACEABLE,         /*! PTP traceability */
   VHD_SDP_STREAM_PROPERTY_REF_CLOCK_NON_PTP_LOCAL_MAC_MSB,    /*! Reference clock (non-PTP) local MAC address (32 most significant bits) */
   VHD_SDP_STREAM_PROPERTY_REF_CLOCK_NON_PTP_LOCAL_MAC_LSB,    /*! Reference clock (non-PTP) local MAC address (32 least significant bits) */
   VHD_SDP_STREAM_PROPERTY_VIDEO_DESTINATION_IP_ADDRESS,       /*! Video destination IP address */
   VHD_SDP_STREAM_PROPERTY_VIDEO_RTP_PAYLOAD_ID,               /*! Video RTP payload ID */
   VHD_SDP_STREAM_PROPERTY_VIDEO_DESTINATION_UDP_PORT,         /*! Video destination UDP port */
   VHD_SDP_STREAM_PROPERTY_VIDEO_STANDARD,                     /*! Video standard (see VHD_ST2110_20_VIDEO_STANDARD) */
   VHD_SDP_STREAM_PROPERTY_VIDEO_SAMPLING,                     /*! Video sampling (see VHD_ST2110_20_SAMPLING) */
   VHD_SDP_STREAM_PROPERTY_VIDEO_BIT_DEPTH,                    /*! Video bit depth (see VHD_ST2110_20_DEPTH) */
   VHD_SDP_STREAM_PROPERTY_VIDEO_COLORIMETRY,                  /*! Video colorimetry (as a string only) */
   VHD_SDP_STREAM_PROPERTY_VIDEO_TCS,                          /*! Video transfer characteristics (as a string only) */
   VHD_SDP_STREAM_PROPERTY_AUDIO_DESTINATION_IP_ADDRESS,       /*! Audio destination IP address */
   VHD_SDP_STREAM_PROPERTY_AUDIO_RTP_PAYLOAD_ID,               /*! Audio RTP payload ID */
   VHD_SDP_STREAM_PROPERTY_AUDIO_DESTINATION_UDP_PORT,         /*! Audio destination UDP port */
   VHD_SDP_STREAM_PROPERTY_AUDIO_NB_CHANNELS,                  /*! Number of audio channels */
   VHD_SDP_STREAM_PROPERTY_AUDIO_SAMPLING_RATE,                /*! Audio sampling rate (see VHD_ST2110_30_SAMPLING_RATE) */
   VHD_SDP_STREAM_PROPERTY_AUDIO_FORMAT,                       /*! Audio format (see VHD_ST2110_30_FORMAT) */
   VHD_SDP_STREAM_PROPERTY_AUDIO_PACKET_TIME,                  /*! Audio packet time (see VHD_ST2110_30_SAMPLING_RATE) */
   VHD_SDP_STREAM_PROPERTY_VIDEO_TRAFFIC_SHAPING_SENDER_TYPE,  /*! Video traffic shaping sender type (see VHD_SDP_ST2110_21_SENDER_TYPE) */
   VHD_SDP_STREAM_PROPERTY_VIDEO_TRAFFIC_SHAPING_TR_OFFSET,    /*! Video traffic shaping TR offset value */
   VHD_SDP_STREAM_PROPERTY_VIDEO_TRAFFIC_SHAPING_CMAX,         /*! Video traffic shaping CMAX value */
   VHD_SDP_STREAM_PROPERTY_AUDIO_CHANNEL_ORDER,                /*! Audio channel order (as a string only) */
   NB_VHD_SDP_STREAM_PROPERTY
} VHD_SDP_STREAM_PROPERTY;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_SDP
*/

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*** VHD_OpenSDPParserHandle ***************************************************/
/*!VHD_OpenSDPParserHandle
   Summary
      Opens a SDP parser instance
   Description
      This functions opens an instance of SDP parser object
      and processes the input buffer.
      It returns a handle to that object through its pSdpParserHandle parameter.
   Parameters
      pSDPBuffer : Buffer string containing the SDP buffer to parse
      InputBufferSize : Size of the input buffer string
      pSdpParserHandle : Pointer to user-allocated variable where the handle is returned
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_OpenSDPParserHandle(char *pSDPBuffer, ULONG InputBufferSize, HANDLE *pSdpParserHandle);
/*** VHD_CloseSDPParserHandle ***************************************************/
/*!VHD_CloseSDPParserHandle
   Summary
      Closes the SDP parser instance
   Description
      This functions closes the SDP parser instance which
      has been previously opened by VHD_OpenSDPParserHandle.
   Parameters
      SdpParserHandle : Handle of the SDP parser
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_CloseSDPParserHandle(HANDLE SdpParserHandle);

/*** VHD_GetSDPBuffer ***************************************************/
/*!VHD_GetSDPBuffer
   Summary
      Gets the SDP buffer string from a SDP parser
   Description
      This function gets the SDP buffer from the given SDP parser handle
      and returns it along with its size through two of its arguments.
      The returned buffer is generated based on the current configuration
      of the SDP parser, which can be controlled by other functions such
      as VHD_SetSDPStreamProperty, VHD_AddSDPField, VHD_SetSDPField, ...
      If the input size of the buffer is smaller than the size of the SDP
      buffer to copy, the required size is written to pBufferSize and an error
      is returned.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      pSDPBuffer : Pointer to user-allocated variable where the SDP buffer is written
      pBufferSize : Pointer to user-allocated variable where the maximum size of 
                     the user buffer is given and the actual size of the buffer is written
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_GetSDPBuffer(HANDLE SdpParserHandle, char *pSDPBuffer, ULONG *pBufferSize);
/*** VHD_SetSDPBuffer ***************************************************/
/*!VHD_SetSDPBuffer
   Summary
      Sets the SDP buffer
   Description
      This function sets the SDP buffer of the SDP parser, effectively
      triggering a parsing operation of the input buffer.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      pSDPBuffer : Buffer string containing the SDP buffer to parse
      BufferSize : Size of the input buffer string
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_SetSDPBuffer(HANDLE SdpParserHandle, char *pSDPBuffer, ULONG BufferSize);

/*** VHD_GetSDPStreamProperty ***************************************************/
/*!VHD_GetSDPStreamProperty
   Summary
      Gets a SDP stream property
   Description
      This function gets the value of a given stream property.
      It differs from the VHD_GetSDPField function in the sense that it provides
      a means to access some attribute of a particular field by consciously parsing
      the buffer knowing how it should be formatted, while VHD_GetSDPField
      returns the entire string value and lets the user do the parsing of that buffer.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      StreamProperty : Stream property (see VHD_SDP_STREAM_PROPERTY enumeration)
      pValue : Pointer to user-allocated variable where the value of the property is returned
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_GetSDPStreamProperty(HANDLE SdpParserHandle, VHD_SDP_STREAM_PROPERTY StreamProperty, ULONG* pValue);
/*** VHD_SetSDPStreamProperty ***************************************************/
/*!VHD_SetSDPStreamProperty
   Summary
      Sets a SDP stream property
   Description
      This function sets the value of a given stream property.
      It differs from the VHD_SetSDPField function in the sense that it provides
      a means to access some attribute of a particular field by consciously parsing
      the buffer knowing how it should be formatted, while VHD_SetSDPField
      sets the entire string value and lets the user properly format the input string.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      StreamProperty : Stream property (see VHD_SDP_STREAM_PROPERTY enumeration)
      Value : Value of the property to set
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_SetSDPStreamProperty(HANDLE SdpParserHandle, VHD_SDP_STREAM_PROPERTY StreamProperty, ULONG Value);

/*** VHD_GetSDPStringStreamProperty ***************************************************/
/*!VHD_GetSDPStringStreamProperty
   Summary
      Gets a SDP stream property as a string
   Description
      This function gets the value of a given stream property.
      It differs from the VHD_GetSDPField function in the sense that it provides
      a means to access some attribute of a particular field by consciously parsing
      the buffer knowing how it should be formatted, while VHD_GetSDPField
      returns the entire string value and lets the user do the parsing of that buffer.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      StreamProperty : Stream property (see VHD_SDP_STREAM_PROPERTY enumeration)
      pFieldBuffer : Value buffer string
      pFieldBufferSize : Pointer to user-allocated variable where the size of the input string buffer is stored
                           and to which the resulting value buffer size is written
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_GetSDPStringStreamProperty(HANDLE SdpParserHandle, VHD_SDP_STREAM_PROPERTY StreamProperty, char *pBuffer, ULONG *pBufferSize);
/*** VHD_SetSDPStringStreamProperty ***************************************************/
/*!VHD_SetSDPStringStreamProperty
   Summary
      Sets a SDP stream property based on a string
   Description
      This function sets the value of a given stream property.
      It differs from the VHD_SetSDPField function in the sense that it provides
      a means to access some attribute of a particular field by consciously parsing
      the buffer knowing how it should be formatted, while VHD_SetSDPField
      sets the entire string value and lets the user properly format the input string.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      StreamProperty : Stream property (see VHD_SDP_STREAM_PROPERTY enumeration)
      pBuffer : Value buffer string
      BufferSize : Size of the value buffer string
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_SetSDPStringStreamProperty(HANDLE SdpParserHandle, VHD_SDP_STREAM_PROPERTY StreamProperty, char *pBuffer, ULONG BufferSize);

/*** VHD_AddSDPDescription ***************************************************/
/*!VHD_AddSDPDescription
   Summary
      Adds a SDP description zone
   Description
      This function add a description zone of a given type and sets its name field value with
      the input buffer string.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      DescriptionType : Description type (see VHD_SDP_DESCRIPTION_TYPE enumeration)
      pInitFieldBuffer : String value of the name field of the new description to add
      InputFieldBufferSize : Size of the field value string
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_AddSDPDescription(HANDLE SdpParserHandle, VHD_SDP_DESCRIPTION_TYPE DescriptionType, char *pInitFieldBuffer, ULONG InputFieldBufferSize);
/*** VHD_RemoveSDPDescription ***************************************************/
/*!VHD_RemoveSDPDescription
   Summary
      Removes a SDP description zone
   Description
      This function removes a description zone identified by its type and index.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      DescriptionType : Description type (see VHD_SDP_DESCRIPTION_TYPE enumeration)
      DescriptionIndex : Description index
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_RemoveSDPDescription(HANDLE SdpParserHandle, VHD_SDP_DESCRIPTION_TYPE DescriptionType, ULONG DescriptionIndex);
/*** VHD_GetNbSDPDescriptions ***************************************************/
/*!VHD_GetNbSDPDescriptions
   Summary
      Gets the number of SDP description zones of a given type
   Description
      This function gets the number of description zones of a given type.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      DescriptionType : Description type (see VHD_SDP_DESCRIPTION_TYPE enumeration)
      pNbDescriptions : Pointer to user-allocated variable where the number of descriptions is written
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_GetNbSDPDescriptions(HANDLE SdpParserHandle, VHD_SDP_DESCRIPTION_TYPE DescriptionType, ULONG *pNbDescriptions);
/*** VHD_GetSDPField ***************************************************/
/*!VHD_GetSDPField
   Summary
      Gets the value of a SDP field of a given type from a given description
   Description
      This functions gets the value of a field identified by a field type and an index
      and belonging to some description zone also identified by its type and index.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      DescriptionType : Description type (see VHD_SDP_DESCRIPTION_TYPE enumeration)
      DescriptionIndex : Description index
      Field : Field type (see VHD_SDP_SESSION_FIELD, VHD_SDP_TIME_FIELD, VHD_SDP_MEDIA_FIELD enumeration)
      FieldIndex : Index of the field
      pFieldBuffer : Field value buffer string
      pFieldBufferSize : Pointer to user-allocated variable where the size of the input string buffer is stored
                           and to which the resulting field value buffer size is written
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_GetSDPField(HANDLE SdpParserHandle, VHD_SDP_DESCRIPTION_TYPE DescriptionType, ULONG DescriptionIndex, ULONG Field, ULONG FieldIndex, char *pFieldBuffer, ULONG *pFieldBufferSize);
/*** VHD_SetSDPField ***************************************************/
/*!VHD_SetSDPField
   Summary
      Sets the value of a SDP field of a given type from a given description
   Description
      This functions sets the value of a field identified by a field type and an index
      and belonging to some description zone also identified by its type and index.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      DescriptionType : Description type (see VHD_SDP_DESCRIPTION_TYPE enumeration)
      DescriptionIndex : Description index
      Field : Field type (see VHD_SDP_SESSION_FIELD, VHD_SDP_TIME_FIELD, VHD_SDP_MEDIA_FIELD enumeration)
      FieldIndex : Index of the field
      pFieldBuffer : Field value buffer string
      FieldBufferSize : Size of the field value string
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_SetSDPField(HANDLE SdpParserHandle, VHD_SDP_DESCRIPTION_TYPE DescriptionType, ULONG DescriptionIndex, ULONG Field, ULONG FieldIndex, char *pFieldBuffer, ULONG FieldBufferSize);
/*** VHD_AddSDPField ***************************************************/
/*!VHD_AddSDPField
   Summary
      Adds a SDP field of a given type from a given description
   Description
      This functions adds field of a given field type and belonging 
      to some description zone also identified by its type and index.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      DescriptionType : Description type (see VHD_SDP_DESCRIPTION_TYPE enumeration)
      DescriptionIndex : Description index
      Field : Field type (see VHD_SDP_SESSION_FIELD, VHD_SDP_TIME_FIELD, VHD_SDP_MEDIA_FIELD enumeration)
      pFieldBuffer : Field value buffer string
      FieldBufferSize : Size of the field value string
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_AddSDPField(HANDLE SdpParserHandle, VHD_SDP_DESCRIPTION_TYPE DescriptionType, ULONG DescriptionIndex, ULONG Field, char *pFieldBuffer, ULONG FieldBufferSize);
/*** VHD_RemoveSDPField ***************************************************/
/*!VHD_RemoveSDPField
   Summary
      Removes a SDP field of a given type from a given description
   Description
      This functions removes a field identified by a field type and an index
      and belonging to some description zone also identified by its type and index.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      DescriptionType : Description type (see VHD_SDP_DESCRIPTION_TYPE enumeration)
      DescriptionIndex : Description index
      Field : Field type (see VHD_SDP_SESSION_FIELD, VHD_SDP_TIME_FIELD, VHD_SDP_MEDIA_FIELD enumeration)
      FieldIndex : Index of the field
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_RemoveSDPField(HANDLE SdpParserHandle, VHD_SDP_DESCRIPTION_TYPE DescriptionType, ULONG DescriptionIndex, ULONG Field, ULONG FieldIndex);
/*** VHD_GetNbSDPFields ***************************************************/
/*!VHD_GetNbSDPFields
   Summary
      Gets the number of SDP fields of a given type
   Description
      This functions gets the number of fields of a given field type
      belonging to some description zone identified by its type and index.
   Parameters
      SdpParserHandle : Handle of the SDP parser
      DescriptionType : Description type (see VHD_SDP_DESCRIPTION_TYPE enumeration)
      DescriptionIndex : Description index
      Field : Field type (see VHD_SDP_SESSION_FIELD, VHD_SDP_TIME_FIELD, VHD_SDP_MEDIA_FIELD enumeration)
      pNbFields : Pointer to user-allocated variable to store the number of fields
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_GetNbSDPFields(HANDLE SdpParserHandle, VHD_SDP_DESCRIPTION_TYPE DescriptionType, ULONG DescriptionIndex, ULONG Field, ULONG *pNbFields);

#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS

#endif //_VIDEOMASTERHD_SDP_H_