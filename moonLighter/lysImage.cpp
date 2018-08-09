#include "stdafx.h"
#include "loadingScene.h"



void loadingScene::lysImageLoading()
{
	_loading->loadImage("윌_화살위", "Image/player/화살위.bmp", 15, 76, true, RGB(255, 0, 255));
	_loading->loadImage("윌_화살아래", "Image/player/화살아래.bmp", 15, 76, true, RGB(255, 0, 255));
	_loading->loadImage("윌_화살왼쪽", "Image/player/화살왼쪽.bmp", 78, 15, true, RGB(255, 0, 255));
	_loading->loadImage("윌_화살오른쪽", "Image/player/화살오른쪽.bmp", 80, 15, 130, 228, true, RGB(255, 0, 255));
	_loading->loadImage("will_hpBar", "Image/player/hpBar.bmp", 150, 50, 130, 228, true, RGB(255, 0, 255));
	_loading->loadImage("will_damaged", "Image/player/will_damaged.bmp", 1280, 720);
	_loading->loadImage("coin", "Image/player/coin.bmp", 16, 16, true, RGB(255,0,255));
	_loading->loadImage("moneyBag", "Image/player/moneyBag.bmp", 64, 65, true, RGB(255,0,255));
	_loading->loadFrameImage("will_damaged2", "Image/player/will_damaged2.bmp", 1200, 1560, 10, 13, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_damaged3", "Image/player/will_damaged3.bmp", 1200, 1560, 10, 13, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will", "Image/player/will_shop.bmp", 1500, 1800, 10, 12, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_dungeon", "Image/player/will_dungeon.bmp", 1200, 1560, 10, 13, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_shortAttack", "Image/player/will_shortAttack1.bmp", 975, 592, 8, 4, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_shortAttack_Damaged2", "Image/player/will_shortAttack_Damaged2.bmp", 975, 592, 8, 4, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_shortAttack_Damaged3", "Image/player/will_shortAttack_Damaged3.bmp", 975, 592, 8, 4, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_shortAttack_shadow", "Image/player/will_shortAttack_shadow.bmp", 975, 592, 8, 4, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_shortSword1", "Image/player/shortSword1.bmp", 480, 160, 3, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_pendant", "Image/player/pendant.bmp", 3400, 83, 40, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_goHome", "Image/player/goHome.bmp", 6572, 192, 31, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_foot", "Image/player/will_foot.bmp", 60, 12, 5, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_dungeon_shadow", "Image/player/will_dungeon_shadow.bmp", 1200, 1560, 10, 13, true, RGB(255, 0, 255));
	_loading->loadFrameImage("number", "Image/player/number.bmp", 77, 12, 11, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("shakeHeart", "Image/player/shakeHeart.bmp", 1860, 42, 31, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_back", "Image/player/will_bow_back.bmp", 657, 100, 9, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_front", "Image/player/will_bow_front.bmp", 603, 87, 9, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_left", "Image/player/will_bow_left.bmp", 1045, 79, 10, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_right", "Image/player/will_bow_right.bmp", 935, 80, 10, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_back_shadow", "Image/player/will_bow_back_shadow.bmp", 657, 100, 9, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_front_shadow", "Image/player/will_bow_front_shadow.bmp", 603, 87, 9, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_left_shadow", "Image/player/will_bow_left_shadow.bmp", 1045, 79, 10, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_right_shadow", "Image/player/will_bow_right_shadow.bmp", 935, 80, 10, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_back_damaged2", "Image/player/will_bow_back_damaged2.bmp", 657, 100, 9, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_front_damaged2", "Image/player/will_bow_front_damaged2.bmp", 603, 87, 9, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_left_damaged2", "Image/player/will_bow_left_damaged2.bmp", 1045, 79, 10, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_right_damaged2", "Image/player/will_bow_right_damaged2.bmp", 935, 80, 10, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_back_damaged3", "Image/player/will_bow_back_damaged3.bmp", 657, 100, 9, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_front_damaged3", "Image/player/will_bow_front_damaged3.bmp", 603, 87, 9, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_left_damaged3", "Image/player/will_bow_left_damaged3.bmp", 1045, 79, 10, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_bow_right_damaged3", "Image/player/will_bow_right_damaged3.bmp", 935, 80, 10, 1, true, RGB(255, 0, 255));
}

void loadingScene::lysSoundLoading()
{
	_loading->loadSound("will_damaged", "./gameSound/will_damaged.wav", false, false);
	_loading->loadSound("will_shortSwordAttack", "./gameSound/will_shortSwordAttack.wav", false, false);
	_loading->loadSound("will_roll", "./gameSound/will_roll.wav", false, false);
	_loading->loadSound("will_step_town_gravel", "./gameSound/will_step_town_gravel.wav", false, false);
	_loading->loadSound("will_death", "./gameSound/will_death.wav", false, false);
	_loading->loadSound("will_pendant_absorb", "./gameSound/will_pendant_absorb.wav", false, false);
	_loading->loadSound("will_pendant_charge", "./gameSound/will_pendant_charge.wav", false, false);
	_loading->loadSound("dungeon_entrance_slime_door_opened_loop", "./gameSound/dungeon_entrance_slime_door_opened_loop.wav", false, false);
	_loading->loadSound("dungeon_entrance_slime_door_close", "./gameSound/dungeon_entrance_slime_door_close.wav", false, false);
	_loading->loadSound("dungeon_entrance_slime_door_absorb", "./gameSound/dungeon_entrance_slime_door_absorb.wav", false, false);
	_loading->loadSound("dungeon_entrance_slime_door_spit", "./gameSound/dungeon_entrance_slime_door_spit.wav", false, false);
}

