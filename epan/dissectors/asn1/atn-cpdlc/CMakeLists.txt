# CMakeLists.txt
#
# Wireshark - Network traffic analyzer
# By Gerald Combs <gerald@wireshark.org>
# Copyright 1998 Gerald Combs
#
# SPDX-License-Identifier: GPL-2.0-or-later
#

set( PROTOCOL_NAME atn-cpdlc )

set( PROTO_OPT )

set( EXPORT_FILES
)

set( EXT_ASN_FILE_LIST
)

set( ASN_FILE_LIST
	${PROTOCOL_NAME}.asn
)

set( EXTRA_DIST
	${ASN_FILE_LIST}
	packet-${PROTOCOL_NAME}-template.c
	${PROTOCOL_NAME}.cnf
)

set( SRC_FILES
	${EXTRA_DIST}
	${EXT_ASN_FILE_LIST}
)

set( A2W_FLAGS -u )

set( EXTRA_CNF
)

ASN2WRS()
