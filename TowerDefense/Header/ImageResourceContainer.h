#pragma once
#include "ImageResource.h"

enum eImageIndex {
	eImage_TitleLogo,
	eImage_TitleBackground,
	eImage_MenuButton,
	eImage_Character1,
	eImage_Character2,
	eImage_Character3,
	eImage_Tower,
	eImage_GameButton,
	eImage_PauseButton,

	eImage_None
};

class cImageResourceContainer : public iInitialization {
private:
	cImageResourceContainer() {
		this->Initialize();
	}
	cImageResourceContainer(const cImageResourceContainer& r) {}
	cImageResourceContainer& operator=(const cImageResourceContainer& r) {}
	~cImageResourceContainer() {
		this->Finalize();
	}
protected:
	std::vector<cImageResource> mImageArray;
public:
	static cImageResourceContainer* GetInstance() {
		static cImageResourceContainer inst;
		return &inst;
	}

	cImageResource* GetElement(eImageIndex Imdex);

	void Initialize() override;
	void Finalize() override;
};