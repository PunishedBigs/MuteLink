#include "modding.h"
#include "recompconfig.h"
#include "global.h"
#include "mutelink.h"

Player* sPlayer;

int voiceSfx[] = {
    NA_SE_VO_LI_SWORD_N, NA_SE_VO_LI_SWORD_L, NA_SE_VO_LI_LASH, NA_SE_VO_LI_HANG, NA_SE_VO_LI_CLIMB_END, NA_SE_VO_LI_DAMAGE_S, NA_SE_VO_LI_FREEZE, NA_SE_VO_LI_FALL_S, NA_SE_VO_LI_FALL_L,
    NA_SE_VO_LI_BREATH_REST, NA_SE_VO_LI_BREATH_DRINK, NA_SE_VO_LI_DOWN, NA_SE_VO_LI_TAKEN_AWAY, NA_SE_VO_LI_HELD, NA_SE_VO_LI_SNEEZE, NA_SE_VO_LI_SWEAT, NA_SE_VO_LI_DRINK, NA_SE_VO_LI_RELAX,
    NA_SE_VO_LI_SWORD_PUTAWAY, NA_SE_VO_LI_GROAN, NA_SE_VO_LI_AUTO_JUMP, NA_SE_VO_LI_MAGIC_NALE, NA_SE_VO_LI_SURPRISE, NA_SE_VO_LI_MAGIC_FROL, NA_SE_VO_LI_PUSH, NA_SE_VO_LI_HOOKSHOT_HANG,
    NA_SE_VO_LI_LAND_DAMAGE_S, NA_SE_VO_LI_MAGIC_START, NA_SE_VO_LI_MAGIC_ATTACK, NA_SE_VO_BL_DOWN, NA_SE_VO_LI_DEMO_DAMAGE, NA_SE_VO_LI_SWORD_N_copy30, NA_SE_VO_DUMMY_32, NA_SE_VO_DUMMY_33,
    NA_SE_VO_DUMMY_34, NA_SE_VO_DUMMY_35, NA_SE_VO_DUMMY_36, NA_SE_VO_DUMMY_37, NA_SE_VO_DUMMY_38, NA_SE_VO_DUMMY_39, NA_SE_VO_NAVY_ENEMY, NA_SE_VO_NAVY_HELLO, NA_SE_VO_NAVY_HEAR, NA_SE_VO_DUMMY_43,
    NA_SE_VO_DUMMY_44, NA_SE_VO_DUMMY_45, NA_SE_VO_DUMMY_46, NA_SE_VO_DUMMY_47, NA_SE_VO_DUMMY_48, NA_SE_VO_DUMMY_49, NA_SE_VO_DUMMY_50, NA_SE_VO_DUMMY_51, NA_SE_VO_DUMMY_52, NA_SE_VO_DUMMY_53,
    NA_SE_VO_DUMMY_54, NA_SE_VO_DUMMY_55, NA_SE_VO_DUMMY_56, NA_SE_VO_DUMMY_57, NA_SE_VO_DUMMY_58, NA_SE_VO_DUMMY_59, NA_SE_VO_DUMMY_60, NA_SE_VO_DUMMY_61, NA_SE_VO_DUMMY_62, NA_SE_VO_DUMMY_63,
    NA_SE_VO_DUMMY_128, NA_SE_VO_DUMMY_129, NA_SE_VO_DUMMY_130, NA_SE_VO_DUMMY_131, NA_SE_VO_DUMMY_132, NA_SE_VO_DUMMY_133, NA_SE_VO_DUMMY_134, NA_SE_VO_DUMMY_135, NA_SE_VO_DUMMY_136, NA_SE_VO_DUMMY_137,
    NA_SE_VO_DUMMY_138, NA_SE_VO_DUMMY_139, NA_SE_VO_DUMMY_140, NA_SE_VO_DUMMY_141, NA_SE_VO_DUMMY_142, NA_SE_VO_DUMMY_143, NA_SE_VO_DUMMY_144, NA_SE_VO_DUMMY_145, NA_SE_VO_DUMMY_146, NA_SE_VO_DUMMY_147,
    NA_SE_VO_DUMMY_148, NA_SE_VO_DUMMY_149, NA_SE_VO_DUMMY_150, NA_SE_VO_DUMMY_151, NA_SE_VO_DUMMY_152, NA_SE_VO_DUMMY_153, NA_SE_VO_DUMMY_154, NA_SE_VO_DUMMY_155, NA_SE_VO_DUMMY_156, NA_SE_VO_DUMMY_157,
    NA_SE_VO_DUMMY_158, NA_SE_VO_DUMMY_159, NA_SE_VO_DUMMY_160, NA_SE_VO_DUMMY_161, NA_SE_VO_DUMMY_162, NA_SE_VO_DUMMY_163, NA_SE_VO_DUMMY_164, NA_SE_VO_DUMMY_165, NA_SE_VO_DUMMY_166, NA_SE_VO_DUMMY_167,
    NA_SE_VO_DUMMY_168, NA_SE_VO_DUMMY_169, NA_SE_VO_DUMMY_170, NA_SE_VO_DUMMY_171, NA_SE_VO_DUMMY_172, NA_SE_VO_DUMMY_173, NA_SE_VO_DUMMY_174, NA_SE_VO_DUMMY_175, NA_SE_VO_DUMMY_176, NA_SE_VO_DUMMY_177,
    NA_SE_VO_DUMMY_178, NA_SE_VO_DUMMY_179, NA_SE_VO_DUMMY_180, NA_SE_VO_DUMMY_181, NA_SE_VO_DUMMY_182, NA_SE_VO_DUMMY_183, NA_SE_VO_DUMMY_184, NA_SE_VO_DUMMY_185, NA_SE_VO_DUMMY_186, NA_SE_VO_DUMMY_187,
    NA_SE_VO_DUMMY_188, NA_SE_VO_DUMMY_189, NA_SE_VO_DUMMY_190, NA_SE_VO_DUMMY_191, NA_SE_VO_DUMMY_192, NA_SE_VO_DUMMY_193, NA_SE_VO_DUMMY_194, NA_SE_VO_DUMMY_195, NA_SE_VO_DUMMY_196, NA_SE_VO_DUMMY_197,
    NA_SE_VO_DUMMY_198, NA_SE_VO_DUMMY_199, NA_SE_VO_DUMMY_200, NA_SE_VO_DUMMY_201, NA_SE_VO_DUMMY_202, NA_SE_VO_DUMMY_203, NA_SE_VO_DUMMY_204, NA_SE_VO_DUMMY_205, NA_SE_VO_DUMMY_206, NA_SE_VO_DUMMY_207,
    NA_SE_VO_DUMMY_208, NA_SE_VO_DUMMY_209, NA_SE_VO_DUMMY_210, NA_SE_VO_DUMMY_211, NA_SE_VO_DUMMY_212, NA_SE_VO_DUMMY_213, NA_SE_VO_DUMMY_214, NA_SE_VO_DUMMY_215, NA_SE_VO_DUMMY_216, NA_SE_VO_DUMMY_217,
    NA_SE_VO_DUMMY_218, NA_SE_VO_DUMMY_219, NA_SE_VO_DUMMY_220, NA_SE_VO_DUMMY_221, NA_SE_VO_DUMMY_222, NA_SE_VO_DUMMY_223, NA_SE_PL_TRANSFORM_VOICE, NA_SE_VO_LK_DRAGGED_DAMAGE, NA_SE_VO_LK_CATCH_DEMO,
    NA_SE_VO_LK_WAKE_UP, NA_SE_VO_LK_USING_UP_ENERGY, NA_SE_VO_LI_POO_WAIT, NA_SE_VO_DUMMY_225, NA_SE_VO_DUMMY_226, NA_SE_VO_DUMMY_227, NA_SE_VO_DUMMY_228, NA_SE_VO_DUMMY_229, NA_SE_VO_DUMMY_230,
    NA_SE_VO_DUMMY_231, NA_SE_VO_DUMMY_232, NA_SE_VO_DUMMY_233, NA_SE_VO_DUMMY_234, NA_SE_VO_DUMMY_235, NA_SE_VO_DUMMY_236, NA_SE_VO_DUMMY_237, NA_SE_VO_DUMMY_238, NA_SE_VO_DUMMY_239, NA_SE_VO_DUMMY_240,
    NA_SE_VO_DUMMY_241, NA_SE_VO_DUMMY_242, NA_SE_VO_DUMMY_243, NA_SE_VO_DUMMY_244, NA_SE_VO_DUMMY_245, NA_SE_VO_DUMMY_246, NA_SE_VO_DUMMY_247, NA_SE_VO_DUMMY_248, NA_SE_VO_DUMMY_249, NA_SE_VO_DUMMY_250,
    NA_SE_VO_DUMMY_251, NA_SE_VO_DUMMY_252, NA_SE_VO_DUMMY_253, NA_SE_VO_DUMMY_254, NA_SE_VO_DUMMY_255
};


RECOMP_HOOK("Play_UpdateMain") void Play_UpdateMain(PlayState* this) {
    sPlayer = GET_PLAYER(this);
}


bool ShouldFormPlaySfx(Player* this) {
    if (recomp_get_config_u32("_mute_human") && (this->transformation == PLAYER_FORM_HUMAN || this->currentMask == PLAYER_MASK_GIANT) && (this->currentMask != PLAYER_MASK_SCENTS)) {
        return false;
    }
    if (recomp_get_config_u32("_mute_deku") && this->transformation == PLAYER_FORM_DEKU) {
        return false;
    }
    if (recomp_get_config_u32("_mute_goron") && this->transformation == PLAYER_FORM_GORON) {
        return false;
    }
    if (recomp_get_config_u32("_mute_zora") && this->transformation == PLAYER_FORM_ZORA) {
        return false;
    }
    if (recomp_get_config_u32("_mute_deity") && this->transformation == PLAYER_FORM_FIERCE_DEITY) {
        return false;
    }
    if (recomp_get_config_u32("_mute_scents") && this->currentMask == PLAYER_MASK_SCENTS) {
        return false;
    }
    else return true;
}

bool IsVoiceEffect(u16 sfxId) {
    sfxId = sfxId | SFX_FLAG;
    for (size_t i = 0; i < sizeof(voiceSfx) / sizeof(voiceSfx[0]); i++) {
        if (sfxId == voiceSfx[i]) {
            return true;
        }
    }
    return false;
}

RECOMP_PATCH void Player_PlaySfx(Player* player, u16 sfxId) {
    if (player->currentMask == PLAYER_MASK_GIANT) {
        if (ShouldFormPlaySfx(player)) {
            Audio_PlaySfx_AtPosWithPresetLowFreqAndHighReverb(&player->actor.projectedPos, sfxId);
        }
        else if (!ShouldFormPlaySfx(player) && !IsVoiceEffect(sfxId)) {
            Audio_PlaySfx_AtPosWithPresetLowFreqAndHighReverb(&player->actor.projectedPos, sfxId);
        }

    } else {
        if (ShouldFormPlaySfx(player)) {
            AudioSfx_PlaySfx(sfxId, &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
        }
        else if (!ShouldFormPlaySfx(player) && !IsVoiceEffect(sfxId)) {
            AudioSfx_PlaySfx(sfxId, &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
        }
    }
}

f32 sGiantsMaskFreq = 0.89167805f;
s8 sGiantsMaskReverbAdd = 0x40;

RECOMP_PATCH void Audio_PlaySfx_GiantsMask(Vec3f* pos, u16 sfxId) {
    if (ShouldFormPlaySfx(sPlayer)) {
        AudioSfx_PlaySfx((sfxId & 0x681F) + 0x20, pos, 4, &sGiantsMaskFreq, &gSfxDefaultFreqAndVolScale,
            &sGiantsMaskReverbAdd);
    }
    else if (!ShouldFormPlaySfx(sPlayer) && !IsVoiceEffect(sfxId)) {
        AudioSfx_PlaySfx((sfxId & 0x681F) + 0x20, pos, 4, &sGiantsMaskFreq, &gSfxDefaultFreqAndVolScale,
            &sGiantsMaskReverbAdd);
    }
}

RECOMP_PATCH void Actor_PlaySfx_Flagged2(Actor* actor, u16 sfxId) {
    if (ShouldFormPlaySfx(sPlayer)) {
        actor->sfxId = sfxId;
        actor->audioFlags &= ~ACTOR_AUDIO_FLAG_SFX_ALL;
        actor->audioFlags |= ACTOR_AUDIO_FLAG_SFX_ACTOR_POS_2;
    }
    else if (!ShouldFormPlaySfx(sPlayer) && !IsVoiceEffect(sfxId)) {
        actor->sfxId = sfxId;
        actor->audioFlags &= ~ACTOR_AUDIO_FLAG_SFX_ALL;
        actor->audioFlags |= ACTOR_AUDIO_FLAG_SFX_ACTOR_POS_2;
    }
}
