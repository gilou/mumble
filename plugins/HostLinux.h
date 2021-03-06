// Copyright 2020 The Mumble Developers. All rights reserved.
// Use of this source code is governed by a BSD-style license
// that can be found in the LICENSE file at the root of the
// Mumble source tree or at <https://www.mumble.info/LICENSE>.

#ifndef HOSTLINUX_H_
#define HOSTLINUX_H_

#include <cstddef>
#include <cstdint>
#include <string>

typedef uint32_t procid_t;
typedef uint64_t procptr_t;

class HostLinux {
protected:
	bool m_ok;
	procid_t m_pid;

public:
	inline bool isOk() const { return m_ok; }

	bool peek(const procptr_t address, void *dst, const size_t size) const;
	procptr_t module(const std::string &module) const;

	static bool isWine(const procid_t id);

	HostLinux(const procid_t pid);
	virtual ~HostLinux();
};

#endif
