#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GJGarageLayer.hpp>

#include <Geode/utils/web.hpp>

#include <string>

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

        auto xpsSprite = CircleButtonSprite::createWithSpriteFrameName(
                "xps-logo-transparent-gold.png"_spr,
                1.2f,
                CircleBaseColor::Green,
                CircleBaseSize::MediumAlt
            );
        auto blankSprite = CCSprite::createWithSpriteFrameName("GJ_longBtn01_001.png");
        auto discordSprite = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");
        auto twitterSprite = CCSprite::createWithSpriteFrameName("gj_twIcon_001.png");
        auto youtubeSprite = CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png");
        auto twitchSprite = CCSprite::createWithSpriteFrameName("gj_twitchIcon_001.png");

		CCLabelBMFont* xpsDashboardLabel = CCLabelBMFont::create("Dashboard", "bigFont.fnt");
		CCLabelBMFont* xpsWebsiteLabel = CCLabelBMFont::create("Website", "bigFont.fnt");

        auto xpsButton = CCMenuItemSpriteExtra::create(
            xpsSprite,
            this,
            menu_selector(MenuLayerMod::onXpsButtonPress)
        );
        xpsButton->setID("xps-button"_spr);

        auto xpsWebsiteButton = CCMenuItemSpriteExtra::create(
            blankSprite,
            this,
            menu_selector(MenuLayerMod::openWebsiteLink)
        );
        xpsWebsiteButton->setID("xps-website-button"_spr);

        auto xpsDashboardButton = CCMenuItemSpriteExtra::create(
            blankSprite,
            this,
            menu_selector(MenuLayerMod::openDashboardLink)
        );
        xpsDashboardButton->setID("xps-dashboard-button"_spr);

        auto xpsDiscordButton = CCMenuItemSpriteExtra::create(
            discordSprite,
            this,
            menu_selector(MenuLayerMod::openDiscordLink)
        );
        xpsDiscordButton->setID("xps-discord-button"_spr);

        auto xpsTwitterButton = CCMenuItemSpriteExtra::create(
            twitterSprite,
            this,
            menu_selector(MenuLayerMod::openTwitterLink)
        );
        xpsTwitterButton->setID("xps-twitter-button"_spr);

        auto xpsYoutubeButton = CCMenuItemSpriteExtra::create(
            youtubeSprite,
            this,
            menu_selector(MenuLayerMod::openYoutubeLink)
        );
        xpsYoutubeButton->setID("xps-youtube-button"_spr);

        auto xpsTwitchButton = CCMenuItemSpriteExtra::create(
            twitchSprite,
            this,
            menu_selector(MenuLayerMod::openTwitchLink)
        );
        xpsTwitchButton->setID("xps-twitch-button"_spr);

        xpsButton->setID("xps-button"_spr);
        xpsWebsiteButton->setID("xps-website-button"_spr);
        xpsDashboardButton->setID("xps-dashboard-button"_spr);

        xpsDashboardLabel->setScale(0.4);
        xpsWebsiteLabel->setScale(0.55f);
        xpsDashboardLabel->setPosition(45, 17.5);
        xpsWebsiteLabel->setPosition(45, 17.5);

        xpsDashboardButton->addChild(xpsDashboardLabel);
        xpsWebsiteButton->addChild(xpsWebsiteLabel);

        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
            bottomMenu->removeChildByID("newgrounds-button");
            if (Mod::get()->getSettingValue<bool>("show-xps-android-launcher-note-button")) {
                bottomMenu->addChild(xpsButton);
            }
            bottomMenu->updateLayout();
        }

        auto xpsButtonsRight = CCMenu::create();
        xpsButtonsRight->setPosition(winSize.width-70.8f, 20);
        xpsButtonsRight->setID("xps-buttons-right"_spr);

        xpsButtonsRight->addChild(xpsDiscordButton);
        xpsButtonsRight->addChild(xpsTwitterButton);
        xpsButtonsRight->addChild(xpsYoutubeButton);
        xpsButtonsRight->addChild(xpsTwitchButton);
        xpsButtonsRight->setLayout(RowLayout::create());

        AxisLayout* xpsButtonsRightLayout = as<AxisLayout*>(xpsButtonsRight->getLayout());
        xpsButtonsRightLayout->setGap(2);
        xpsButtonsRight->updateLayout();

        if (!Mod::get()->getSettingValue<bool>("alternate-menu-buttons")) {
            auto xpsButtonsLeft = CCMenu::create();
            xpsButtonsLeft->setID("xps-buttons-left"_spr);
            xpsButtonsLeft->setPosition(55, 15);
            xpsButtonsLeft->addChild(xpsWebsiteButton);
            xpsButtonsLeft->addChild(xpsDashboardButton);
            xpsWebsiteButton->setPositionY(10);
            xpsDashboardButton->setPositionY(42.5f);
            this->addChild(xpsButtonsLeft);
            auto profileName = this->getChildByID("player-username");
            auto profileButton = this->getChildByID("profile-menu");
            profileButton->setPosition(profileButton->getPositionX()+20, profileButton->getPositionY()+20);
            profileName->setPosition(profileName->getPositionX()+20, profileName->getPositionY()+20);
        } else {
            xpsButtonsRight->addChild(xpsWebsiteButton);
            xpsButtonsRight->addChild(xpsDashboardButton);
            xpsWebsiteButton->setPosition(winSize.width-285, 50);
            xpsDashboardButton->setPosition(winSize.width-285, 82.5f);
        }

        this->addChild(xpsButtonsRight);

        return true;
    }

    void onXpsButtonPress(CCObject*) {
        geode::createQuickPopup(
            "XPS",
            "Welcome to XPS 3.0, If you need any support, or have questions, Join the Discord.\n\nXPS Android launcher is coming soon, which will help manage all Android versions if you use an Android Device.",
            "Dismiss", "Join the Discord",
            [this](auto, bool discordBtn) {
                if (discordBtn) {
                    web::openLinkInBrowser("https://xps.lncvrt.xyz/discord");
                }
                geode::createQuickPopup(
                    "Hide Button?",
                    "Would you like to hide the XPS Button?",
                    "Yes", "No",
                    [this](auto, bool noButton) {
                        if (!noButton) {
                            hideXpsButton();
                        }
                    }
                );
            }
        );
    }

    void hideXpsButton() {
        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
            bottomMenu->removeChildByID("xps-button"_spr);
            bottomMenu->updateLayout();
            Mod::get()->setSettingValue<bool>("show-xps-android-launcher-note-button", false);
        }
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
