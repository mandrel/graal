/*
 * Copyright (c) 2019, 2020, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */
#include "management.h"
#include "jmm_common.h"

#include <trufflenfi.h>
#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


JNIEXPORT void* JNICALL initializeManagementContext(TruffleEnv *truffle_env, void* (*fetch_by_name)(const char *), int version) {
	if (version == JMM_VERSION_1_0) {
		return initializeManagementContext8(truffle_env, fetch_by_name);
	} else if (version == JMM_VERSION_2) {
		return initializeManagementContext11(truffle_env, fetch_by_name);
	} else {
		return (void*)0;
	}
}

JNIEXPORT void JNICALL disposeManagementContext(TruffleEnv *truffle_env, void* management_ptr, int version) {
    if (version == JMM_VERSION_1_0) {
		disposeManagementContext8(truffle_env, management_ptr);
	} else if (version == JMM_VERSION_2) {
		disposeManagementContext11(truffle_env, management_ptr);
	}
}

