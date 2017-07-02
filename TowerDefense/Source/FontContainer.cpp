#include "../Header/FontContainer.h"

int cFontContainer::GetElement(eFontIndex Index) {
	return mFontArray[Index];
}

void cFontContainer::SetElement(eFontIndex Index, const int Value) {
	mFontArray[Index] = Value;
}

void cFontContainer::Initialize() {
	mFontArray.resize(eFontIndex::eFont_None);
}

void cFontContainer::Finalize() {
	for (int i = 0; i < eFontIndex::eFont_None; i++) {
		DeleteFontToHandle(mFontArray[i]);
	}
	//for (auto i : mImageArray) {
	//	i.Finalize();
	//}
	// ���Ō�1�]�v�ȏ��������邩��_��
	mFontArray.clear();
}