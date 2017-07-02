#pragma once
#include "Include.h"

enum eFontIndex {
	eFont_MainFont,
	eFont_GameInfoFont,
	eFont_GameMoneyFont,

	eFont_None
};

class cFontContainer : public iInitialization {
private:
	cFontContainer() {
		this->Initialize();
	}
	cFontContainer(const cFontContainer& r) {}
	cFontContainer& operator=(const cFontContainer& r) {}
	~cFontContainer() {
		this->Finalize();
	}
protected:
	std::vector<int> mFontArray;
public:
	static cFontContainer* GetInstance() {
		static cFontContainer inst;
		return &inst;
	}

	int GetElement(eFontIndex Index);
	void SetElement(eFontIndex Index, const int Value);

	void Initialize() override;
	void Finalize() override;
};