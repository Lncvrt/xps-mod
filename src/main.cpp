#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/modify/ProfilePage.hpp>

#include <Geode/utils/web.hpp>

#include <string>
#include <matjson.hpp>

using namespace geode::prelude;

void saveIcons() {
    auto gm = GameManager::get();
    Mod::get()->setSavedValue<int>("icons/cube", gm->m_playerFrame);
    Mod::get()->setSavedValue<int>("icons/ship", gm->m_playerShip);
    Mod::get()->setSavedValue<int>("icons/ball", gm->m_playerBall);
    Mod::get()->setSavedValue<int>("icons/ufo", gm->m_playerBird);
    Mod::get()->setSavedValue<int>("icons/wave", gm->m_playerDart);
    Mod::get()->setSavedValue<int>("icons/robot", gm->m_playerRobot);
    Mod::get()->setSavedValue<int>("icons/spider", gm->m_playerSpider);
    Mod::get()->setSavedValue<int>("icons/swing", gm->m_playerSwing);
    Mod::get()->setSavedValue<int>("icons/color", gm->m_playerColor);
    Mod::get()->setSavedValue<int>("icons/color2", gm->m_playerColor2);
    Mod::get()->setSavedValue<int>("icons/colorglow", gm->m_playerGlowColor);
    Mod::get()->setSavedValue<int>("icons/streak", gm->m_playerStreak);
    Mod::get()->setSavedValue<int>("icons/shipfire", gm->m_playerShipFire);
    Mod::get()->setSavedValue<int>("icons/death", gm->m_playerDeathEffect);
    Mod::get()->setSavedValue<int>("icons/jetpack", gm->m_playerJetpack);
    Mod::get()->setSavedValue<int>("icons/glow", gm->m_playerGlow);
}

void loadIcons() {
    auto gm = GameManager::get();
    gm->m_playerFrame = Mod::get()->getSavedValue<int>("icons/cube", gm->m_playerFrame);
    gm->m_playerShip = Mod::get()->getSavedValue<int>("icons/ship", gm->m_playerShip);
    gm->m_playerBall = Mod::get()->getSavedValue<int>("icons/ball", gm->m_playerBall);
    gm->m_playerBird = Mod::get()->getSavedValue<int>("icons/ufo", gm->m_playerBird);
    gm->m_playerDart = Mod::get()->getSavedValue<int>("icons/wave", gm->m_playerDart);
    gm->m_playerRobot = Mod::get()->getSavedValue<int>("icons/robot", gm->m_playerRobot);
    gm->m_playerSpider = Mod::get()->getSavedValue<int>("icons/spider", gm->m_playerSpider);
    gm->m_playerSwing = Mod::get()->getSavedValue<int>("icons/swing", gm->m_playerSwing);
    gm->m_playerColor = Mod::get()->getSavedValue<int>("icons/color", gm->m_playerColor);
    gm->m_playerColor2 = Mod::get()->getSavedValue<int>("icons/color2", gm->m_playerColor2);
    gm->m_playerGlowColor = Mod::get()->getSavedValue<int>("icons/colorglow", gm->m_playerGlowColor);
    gm->m_playerStreak = Mod::get()->getSavedValue<int>("icons/streak", gm->m_playerStreak);
    gm->m_playerShipFire = Mod::get()->getSavedValue<int>("icons/shipfire", gm->m_playerShipFire);
    gm->m_playerDeathEffect = Mod::get()->getSavedValue<int>("icons/death", gm->m_playerDeathEffect);
    gm->m_playerJetpack = Mod::get()->getSavedValue<int>("icons/jetpack", gm->m_playerJetpack);
    gm->m_playerGlow = Mod::get()->getSavedValue<int>("icons/glow", gm->m_playerGlow);
}

class $modify(MenuLayerMod, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }
        loadIcons();

        this->removeChildByID("social-media-menu");
        this->removeChildByID("more-games-menu");

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto xpsSprite = CCSprite::create("xps-logo-transparent-gold.png"_spr);
        auto blankSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn01_001.png");
        auto discordSprite = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");
        auto twitterSprite = CCSprite::createWithSpriteFrameName("gj_twIcon_001.png");
        auto youtubeSprite = CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png");
        auto twitchSprite = CCSprite::createWithSpriteFrameName("gj_twitchIcon_001.png");

		CCLabelBMFont* xpsDashboardLabel = CCLabelBMFont::create("Dashboard", "bigFont.fnt");
		CCLabelBMFont* xpsWebsiteLabel = CCLabelBMFont::create("Website", "bigFont.fnt");

        auto xpsButton = CCMenuItemSpriteExtra::create(
            CircleButtonSprite::create(xpsSprite),
            this,
            menu_selector(MenuLayerMod::onXpsButtonPress)
        );
        xpsButton->setID("xps-button"_spr);

        auto xpsWebsiteButton = CCMenuItemSpriteExtra::create(
            blankSprite,
            this,
            menu_selector(MenuLayerMod::openWebsiteLink)
        );
        xpsWebsiteButton->setID("website-button"_spr);

        auto xpsDashboardButton = CCMenuItemSpriteExtra::create(
            blankSprite,
            this,
            menu_selector(MenuLayerMod::openDashboardLink)
        );
        xpsDashboardButton->setID("dashboard-button"_spr);

        auto xpsDiscordButton = CCMenuItemSpriteExtra::create(
            discordSprite,
            this,
            menu_selector(MenuLayerMod::openDiscordLink)
        );
        xpsDiscordButton->setID("discord-button"_spr);

        auto xpsTwitterButton = CCMenuItemSpriteExtra::create(
            twitterSprite,
            this,
            menu_selector(MenuLayerMod::openTwitterLink)
        );
        xpsTwitterButton->setID("twitter-button"_spr);

        auto xpsYoutubeButton = CCMenuItemSpriteExtra::create(
            youtubeSprite,
            this,
            menu_selector(MenuLayerMod::openYoutubeLink)
        );
        xpsYoutubeButton->setID("youtube-button"_spr);

        auto xpsTwitchButton = CCMenuItemSpriteExtra::create(
            twitchSprite,
            this,
            menu_selector(MenuLayerMod::openTwitchLink)
        );
        xpsTwitchButton->setID("twitch-button"_spr);

        xpsButton->setID("xps-button"_spr);
        xpsWebsiteButton->setID("website-button"_spr);
        xpsDashboardButton->setID("dashboard-button"_spr);

        xpsDashboardLabel->setScale(0.4);
        xpsWebsiteLabel->setScale(0.55f);
        xpsDashboardLabel->setPosition(45, 17.5);
        xpsWebsiteLabel->setPosition(45, 17.5);

        xpsDashboardButton->addChild(xpsDashboardLabel);
        xpsWebsiteButton->addChild(xpsWebsiteLabel);
        
        xpsSprite->setScale(0.55f);

        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
            bottomMenu->removeChildByID("newgrounds-button");
            bottomMenu->addChild(xpsButton);
            bottomMenu->updateLayout();
        }

        auto xpsButtonsRight = CCMenu::create();
        auto xpsButtonsLeft = CCMenu::create();
        //i need to redo positions and calculate this again lmao
        xpsButtonsRight->setPosition(winSize.width-78, 20);
        xpsButtonsLeft->setPosition(55, 15);
        xpsButtonsRight->setID("xps-buttons-right"_spr);
        xpsButtonsLeft->setID("xps-buttons-left"_spr);
        
        xpsButtonsRight->addChild(xpsDiscordButton);
        xpsButtonsRight->addChild(xpsTwitterButton);
        xpsButtonsRight->addChild(xpsYoutubeButton);
        xpsButtonsRight->addChild(xpsTwitchButton);
        xpsButtonsLeft->addChild(xpsWebsiteButton);
        xpsButtonsLeft->addChild(xpsDashboardButton);
        xpsButtonsRight->setLayout(RowLayout::create());
        xpsWebsiteButton->setPositionY(10);
        xpsDashboardButton->setPositionY(42.5);

        AxisLayout* xpsButtonsRightLayout = as<AxisLayout*>(xpsButtonsRight->getLayout());
        xpsButtonsRightLayout->setGap(2);
        xpsButtonsRight->updateLayout();

        this->addChild(xpsButtonsRight);
        this->addChild(xpsButtonsLeft);

        auto profileName = this->getChildByID("player-username");
        auto profileButton = this->getChildByID("profile-menu");
        profileButton->setPosition(101,125);
        profileName->setPosition(57,161);
        // (^) this needs to be done properly (i think i cant remember)

        return true;
    }

    void onXpsButtonPress(CCObject*) {
        FLAlertLayer::create("XPS", "Welcome to XPS 3.0, Xytriza is working on making XPS unique but it may take some time. Hope you enjoy playing at the time of this being updated.", "OK")->show();
    }

    void openWebsiteLink(CCObject*) {
        web::openLinkInBrowser("https://xps.lncvrt.xyz/");
    }

    void openDashboardLink(CCObject*) {
        web::openLinkInBrowser("https://xps.lncvrt.xyz/dashboard/");
    }

    void openDiscordLink(CCObject*) {
        web::openLinkInBrowser("https://xps.lncvrt.xyz/discord");
    }

    void openTwitterLink(CCObject*) {
        web::openLinkInBrowser("https://xps.lncvrt.xyz/twitter");
    }

    void openYoutubeLink(CCObject*) {
        web::openLinkInBrowser("https://xps.lncvrt.xyz/youtube");
    }

    void openTwitchLink(CCObject*) {
        web::openLinkInBrowser("https://xps.lncvrt.xyz/twitch");
    }
};

class $modify(LoadingLayer) {
    struct Fields {
        EventListener<web::WebTask> m_listener;
    };

    bool init(bool p0) {
        if (!LoadingLayer::init(p0)) {
            return false;
        }

        this->getChildByID("cocos2d-logo")->setVisible(false);
        this->getChildByID("fmod-logo")->setVisible(false);

        if (auto label = static_cast<CCLabelBMFont*>(this->getChildByID("geode-small-label"))) {
            label->setString("XPS: Loading...");
        }

        //uhhhh i dont even know what i was trying to accomplish here
        // m_fields->m_listener.bind([] (web::WebTask::Event* e) {
        //     if (web::WebResponse* res = e->getValue()) {
        //         auto result = res->string().unwrap();
        //         auto parsed = matjson::parse(result);
        //         if (!parsed) {
        //             log::error("Failed to parse json: {}", parsed.unwrapErr());
        //             return true;
        //         }
        //         matjson::Value object = parsed.unwrap();
        //         auto resultVersion = object["version"].asString().unwrap();
        //         if (resultVersion != "1.0.0-alpha2") {

        //         }
        //     }
        // });

        // auto req = web::WebRequest();
        // m_fields->m_listener.setFilter(req.get("https://xps-api.lncvrt.xyz/versions/gd/windows"));

        return true;
    }
};

class $modify(GameManager) {
    bool isIconUnlocked(int iconID, IconType type) {
        return true;
    }

    bool isColorUnlocked(int p0, UnlockType p1) {
        return true;
    }
};

class $modify(GJGarageLayer) {
    void onBack(cocos2d::CCObject* sender) {
        saveIcons();
        GJGarageLayer::onBack(sender);
    }

    bool init() {
        loadIcons();
        return GJGarageLayer::init();
    }
};

//this was meant to be like profile comments so you could see what other people wrote but i dont think this will happen 💀
//if theres some lib that lets me do list view stuff then ill considor actually adding this
// class $modify(ProfilePageMod, ProfilePage) {
//     void onXpsButtonPress(CCObject*) {
//         FLAlertLayer::create("XPS", "", "OK")->show();
//     }

//     void getUserInfoFinished(GJUserScore *p0){
//         ProfilePage::getUserInfoFinished(p0);

//         auto children = as<CCLayer*>(this->getChildren()->objectAtIndex(0));
//         auto menu = as<CCMenu*>(children->getChildren()->objectAtIndex(16));

//         auto xpsSprite = CCSprite::create("xps-profile-messages-button.png"_spr);

//         auto xpsButton = CCMenuItemSpriteExtra::create(
//             xpsSprite,
//             this,
//             menu_selector(ProfilePageMod::onXpsButtonPress)
//         );
//         xpsButton->setID("xps-button"_spr);

//         menu->addChild(xpsButton);
//         menu->updateLayout();

//         BoomListView* myListView = new BoomListView();
//         const char* myTitle = "My Title";
//         cocos2d::ccColor4B myColor = cocos2d::ccColor4B{161, 88, 44, 255};
//         float myWidth = 340.0f;
//         float myHeight = 140.0f;

//         auto result = GJCommentListLayer::create(myListView, myTitle, myColor, myWidth, myHeight, false);
//         result->setPosition(100, 85);

//         // this->addChild(result);
//         // children->setVisible(false);
//     }
// };