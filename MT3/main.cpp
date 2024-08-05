#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LE2C_23_フジワラ_リオ";

struct Vector3 {
	float x, y, z;
};

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 ret;
	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.z = v1.z + v2.z;
	return ret;
}

//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 ret;
	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	ret.z = v1.z - v2.z;
	return ret;
}

//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 ret;
	ret.x = scalar * v.x;
	ret.y = scalar * v.y;
	ret.z = scalar * v.z;
	return ret;
}

//内積
float Dot(const Vector3& v1, const Vector3& v2) {
	float ret;
	ret = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	return ret;
}

//長さ（ノルム）
float Length(const Vector3& v) {
	float ret;
	ret = float(sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
	return ret;
}

//正規化
Vector3 Normalize(const Vector3& v) {
	float mid;
	Vector3 ret;
	mid = float(sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
	ret.x = v.x / mid;
	ret.y = v.y / mid;
	ret.z = v.z / mid;
	return ret;
}

static const int kColumnWidth = 60;
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Vector3 v1{ 1.0f,3.0f,-5.0f };
	Vector3 v2{ 4.0f,-1.0f,2.0f };
	float k = { 4.0f };

	Vector3 resultAdd = Add(v1, v2);
	Vector3 resultSubtract = Subtract(v1, v2);
	Vector3 resultMultiply = Multiply(k, v1);
	float resultDot = Dot(v1, v2);
	float resultLength = Length(v1);
	Vector3 resultNormalize = Normalize(v2);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0, 0, resultAdd, " : Add");
		VectorScreenPrintf(0, kColumnWidth, resultSubtract, "  : Subtract");
		VectorScreenPrintf(0, kColumnWidth * 2, resultMultiply, "  : Multiply");
		Novice::ScreenPrintf(0, kColumnWidth * 3, "%.02f  : Dot", resultDot);
		Novice::ScreenPrintf(0, kColumnWidth * 4, "%.02f  : Length", resultLength);
		VectorScreenPrintf(0, kColumnWidth * 5, resultNormalize, "  : Nomalize");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
