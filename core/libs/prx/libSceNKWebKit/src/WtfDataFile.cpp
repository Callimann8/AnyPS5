/*
 * Derived from Source/WTF/wtf/DataLog.cpp
 * at https://github.com/neonmodder123/PS5-WebKit-11.x/tree/80f77e94c63ee7202eec3d4b5b1a021dd89011ba/Source/WTF/wtf
 *
 * Copyright (C) 2012-2022 Apple Inc. All rights reserved.
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

#include "prx/libSceNKWebKit/include/WtfDataFileExports.hpp"
#include "prx/libSceNKWebKit/include/WtfExports.hpp"
#include "prx/libkernel/include/Api.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>

extern "C" {

Jsc::WtfAbi::PrintStream& APS5_VABI _ZN3WTF8dataFileEv() {
    return *WtfDataFile_nid_no_patch();
}

void APS5_VABI _ZN3WTF11setDataFileEPKc(const char* path) {
    constexpr std::size_t maxPathLength = 1024;
    Jsc::WtfAbi::FilePrintStream* file = nullptr;
    char formattedPath[maxPathLength + 1];
    const char* pathToOpen = path;
    if (path) {
        if (const char* pidFormat = std::strstr(path, "%pid")) {
            std::size_t pathCharactersAvailable = std::min(maxPathLength, static_cast<std::size_t>(pidFormat - path));
            std::strncpy(formattedPath, path, pathCharactersAvailable);
            char* nextDest = formattedPath + pathCharactersAvailable;
            pathCharactersAvailable = maxPathLength - pathCharactersAvailable;
            if (pathCharactersAvailable) {
                const int pidTextLength = std::snprintf(nextDest, pathCharactersAvailable, "%d", getpid_nid_postfix());
                if (pidTextLength >= 0 && static_cast<std::size_t>(pidTextLength) < pathCharactersAvailable) {
                    pathCharactersAvailable -= static_cast<std::size_t>(pidTextLength);
                    nextDest += pidTextLength;
                    std::strncpy(nextDest, pidFormat + 4, pathCharactersAvailable);
                }
            }
            formattedPath[maxPathLength] = '\0';
            pathToOpen = formattedPath;
        }
        Jsc::WtfAbi::FilePrintStreamPtr opened{};
        file = _ZN3WTF15FilePrintStream4openEPKcS2_(&opened, pathToOpen, "w")->pointer;
        if (file)
            WTFLogAlways("*** DataLog output to \"%s\" ***\n", pathToOpen);
        else
            WTFLogAlways("Warning: Could not open DataLog file %s for writing.\n", pathToOpen);
    }
    WtfSetLockedDataFile_nid_no_patch(file);
}

void APS5_VABI _ZN3WTF15FilePrintStreamD0Ev(Jsc::WtfAbi::FilePrintStream* self) {
    WtfFilePrintStreamDelete_nid_no_patch(self);
}

void APS5_VABI _ZN3WTF15FilePrintStreamD1Ev(Jsc::WtfAbi::FilePrintStream* self) {
    WtfFilePrintStreamDestroy_nid_no_patch(self);
}

void APS5_VABI _ZN3WTF15FilePrintStreamD2Ev(Jsc::WtfAbi::FilePrintStream* self) {
    WtfFilePrintStreamDestroy_nid_no_patch(self);
}

}
