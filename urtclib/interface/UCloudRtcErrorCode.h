#ifndef _UCLOUD_RTC_ERROR_CODE_H_
#define _UCLOUD_RTC_ERROR_CODE_H_

typedef enum _tUCloudRtcCallbackErrCode {
	UCLOUD_RTC_CALLBACK_ERR_CODE_OK = 0,
	UCLOUD_RTC_CALLBACK_ERR_SERVER_CON_FAIL = 5000, //����������ʧ��
	UCLOUD_RTC_CALLBACK_ERR_INVAILDSTATE, // ��������ӶϿ�
	UCLOUD_RTC_CALLBACK_ERR_INVAILDPAGRAM,
	UCLOUD_RTC_CALLBACK_ERR_SERVER_DIS, // ��������ӶϿ�
	UCLOUD_RTC_CALLBACK_ERR_SAME_CMD,  //�ظ��ĵ���
	UCLOUD_RTC_CALLBACK_ERR_NOT_IN_ROOM, //δ���뷿�� �޷����в��� 
	UCLOUD_RTC_CALLBACK_ERR_ROOM_JOINED, // �Ѽ��뷿�� �������
	UCLOUD_RTC_CALLBACK_ERR_SDK_INNER,   // SDK �ڲ�����
	UCLOUD_RTC_CALLBACK_ERR_ROOM_RECONNECTING, // ������ �����޷�Ͷ��      
	UCLOUD_RTC_CALLBACK_ERR_STREAM_PUBED,  // ���Ѿ�����  ���跢��
	UCLOUD_RTC_CALLBACK_ERR_PUB_NO_DEV,  // �����޿��� ��Ƶ ��Ƶ�豸
	UCLOUD_RTC_CALLBACK_ERR_STREAM_NOT_PUB, //��û�з��� �޷��������в���
	UCLOUD_RTC_CALLBACK_ERR_STREAM_SUBED,  //���Ѿ�����  ���趩��
	UCLOUD_RTC_CALLBACK_ERR_STREAM_NO_SUB, //��û�ж���  �޷�
	UCLOUD_RTC_CALLBACK_ERR_SUB_NO_USER,   //�޶�Ӧ���û� �޷�����
	UCLOUD_RTC_CALLBACK_ERR_SUB_NO_STREAM,  // �޶�Ӧ��ý����
	UCLOUD_RTC_CALLBACK_ERR_USER_LEAVING, // �û������뿪����  �޷�������������
	UCLOUD_RTC_CALLBACK_ERR_NO_HAS_TRACK,  //�޶�Ӧ��ý����
	UCLOUD_RTC_CALLBACK_ERR_MSG_TIMEOUT, // ��Ϣ����ʱ
}tUCloudRtcCallbackErrCode;

typedef enum _tUCloudRtcReturnErrCode {
	UCLOUD_RTC_RETURN_ERR_CODE_OK = 0,
	UCLOUD_RTC_RETURN_ERR_AUTO_PUB = 1000, //�Զ�����
	UCLOUD_RTC_RETURN_ERR_AUTO_SUB, //�Զ�����
	UCLOUD_RTC_RETURN_ERR_NOT_INIT, //����û�г�ʼ��
	UCLOUD_RTC_RETURN_ERR_IN_ROOM, //�Ѿ����뷿��
	UCLOUD_RTC_RETURN_ERR_NOT_IN_ROOM, // δ���뷿��
	UCLOUD_RTC_RETURN_ERR_NOT_PUB_TRACK, //δ������Ӧý��
	UCLOUD_RTC_RETURN_ERR_INVAILED_PARGRAM,// ��Ч����
	UCLOUD_RTC_RETURN_ERR_INVAILED_WND_HANDLE,// ��Ч���ھ��
	UCLOUD_RTC_RETURN_ERR_INVAILED_MEDIA_TYPE,// ��Чý������
	UCLOUD_RTC_RETURN_ERR_SUB_ONEMORE,// ���ٶ���һ��ý��
	UCLOUD_RTC_RETURN_ERR_NO_PUB_ROLE, //�޷���Ȩ��
	UCLOUD_RTC_RETURN_ERR_NO_SUB_ROLE, //�޶���Ȩ��
	UCLOUD_RTC_RETURN_ERR_CAM_NOT_ENABLE, //û�����ñ���cam ����
	UCLOUD_RTC_RETURN_ERR_SCREEN_NOT_ENABLE, //û�����ñ���screen ����
	UCLOUD_RTC_RETURN_ERR_AUDIO_MODE,        // ����Ƶģʽ
	UCLOUD_RTC_RETURN_ERR_SECKEY_INVALID ,    // seckey ��Ч
	UCLOUD_RTC_RETURN_ERR_INVAILD_FILEPATH,
	UCLOUD_RTC_RETURN_ERR_NOT_SUPORT_AUDIO_FORMAT,
}tUCloudRtcReturnErrCode;

#endif

