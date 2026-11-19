// Derived from Source/WebCore/platform/graphics/iso/ISOVTTCue.h@73a35b43be7ae44c084885bd3fa4b403e59723c8
/*
 * Copyright (C) 2014-2020 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "prx/libc/include/general/VabiMacros.hpp"
#include "prx/libSceNKWebKit/include/IsoBoxExports.hpp"
#include "prx/libSceNKWebKit/include/MediaExports.hpp"
#include "prx/libSceNKWebKit/include/WebCoreExports.hpp"
#include "prx/libSceNKWebKit/include/WtfExports.hpp"
#include "prx/libSceNKWebKit/src/WtfTextAbi.hpp"

#include <cmath>
#include <stdexcept>

extern "C" {

WebCore::FourCC APS5_VABI _ZN7WebCore12ISOWebVTTCue11boxTypeNameEv() {
    return WebCore::FourCC("vttc");
}

NKWebKit::WtfAbi::String APS5_VABI _ZNK7WebCore12ISOWebVTTCue12toJSONStringEv(const NKWebKit::IsoAbi::WebVTTCue* self) {
    using namespace NKWebKit::WtfAbi;
    if (!self) throw std::invalid_argument("ISOWebVTTCue::toJSONString: null this");
    StringBuilder builder{};
    builder.shouldCrashOnOverflow = true;
    builder.is8Bit = true;
    auto appendString = [&](const char* key, const String& value) {
        AppendCString(builder, key);
        _ZN3WTF13StringBuilder22appendQuotedJSONStringERKNS_6StringE(&builder, _ZN3WTF28encodeWithURLEscapeSequencesERKNS_6StringE(value));
    };
    auto appendDouble = [&](const char* key, const NKWebKit::MediaAbi::MediaTime& time) {
        AppendCString(builder, key);
        double value = _ZNK3WTF9MediaTime8toDoubleEv(&time);
        AppendCString(builder, std::isfinite(value) ? NumberToString(value).c_str() : "null");
    };
    appendString("{\"sourceId\":", self->sourceID);
    appendString(",\"id\":", self->identifier);
    appendString(",\"originalStartTime\":", self->originalStartTime);
    appendString(",\"settings\":", self->settings);
    appendDouble(",\"presentationTime\":", self->presentationTime);
    appendDouble(",\"duration\":", self->duration);
    AppendCharacter(builder, '}');
    String result = ToString(builder);
    Clear(builder);
    return result;
}

}
