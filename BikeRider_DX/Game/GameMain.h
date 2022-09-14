//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  �Q�[���S�̂Ɋւ���w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

// �萔�̒�` ==============================================================
// <�V�X�e��> ----------------------------------------------------------
#define GAME_TITLE "Sample Game"        // �Q�[���^�C�g��


// <���> --------------------------------------------------------------
#define SCREEN_WIDTH    (640)                  // ��ʂ̕�[pixel]
#define SCREEN_HEIGHT   (480)                  // ��ʂ̍���[pixel]

#define SCREEN_TOP      (0)                    // ��ʂ̏�[
#define SCREEN_BOTTOM   (SCREEN_HEIGHT)        // ��ʂ̉��[
#define SCREEN_LEFT     (0)                    // ��ʂ̍��[
#define SCREEN_RIGHT    (SCREEN_WIDTH)         // ��ʂ̉E�[

#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // ��ʂ̒���(X���W)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // ��ʂ̒���(Y���W)

enum class GAME_SCENE : int
{
	NONE,

	TITLE,
	PLAY,
};

class IScene;

// �֐��̐錾 ==============================================================
// <�Q�[��> ------------------------------------------------------------


class GameMain
{
private:

	// �����Ƀ����o�𑝂₷

	// ���̃V�[���ԍ�
	GAME_SCENE mNextScene;

	// �V�[��
	IScene* mpScene;

public:
	
	// �R���X�g���N�^
	GameMain();

	// �f�X�g���N�^
	~GameMain();

	void InitializeGame();    // �Q�[���̏���������
	void UpdateGame();        // �Q�[���̍X�V����
	void RenderGame();        // �Q�[���̕`�揈��
	void FinalizeGame();      // �Q�[���̏I������

	// �V�[���֌W����

	// �V�[���̍쐬
	void CreateScene();

	// �V�[���̍폜
	void DeleteScene();
};