// license:BSD-3-Clause
// copyright-holders:Robbbert



DRIVER_INIT_MEMBER( neogeo_hbmame, rotdb )
{
	DRIVER_INIT_CALL(neogeo);
	m_sprgen->m_fixed_layer_bank_type = 1;
	m_cmc_prot->kof2000_neogeo_gfx_decrypt(spr_region, spr_region_size, fix_region, fix_region_size, ROTD_GFX_KEY);
	m_pcm2_prot->neo_pcm2_snk_1999(ym_region, ym_region_size, 16);
}

DRIVER_INIT_MEMBER( neogeo_hbmame, rotdd )
{
	DRIVER_INIT_CALL(neogeo);
	m_sprgen->m_fixed_layer_bank_type = 1;
	m_cmc_prot->neogeo_sfix_decrypt(spr_region, spr_region_size, fix_region, fix_region_size);
	m_pcm2_prot->neo_pcm2_snk_1999(ym_region, ym_region_size, 16);
}

DRIVER_INIT_MEMBER( neogeo_hbmame, rotdnd )
{
	DRIVER_INIT_CALL(neogeo);
	m_sprgen->m_fixed_layer_bank_type = 1;
	m_cmc_prot->neogeo_sfix_decrypt(spr_region, spr_region_size, fix_region, fix_region_size);
}



ROM_START( rotdb ) /* Rage of the Dragons - Hack by Ydmis - (Console mode enabled - can choose Abubo and Johann) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264b.p1", 0x000000, 0x800000, CRC(66d05f5b) SHA1(8114262695229ec8af22001569481007a30dc977) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdb1 )
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264b1.p1", 0x000000, 0x800000, CRC(8bf2d91e) SHA1(5b0e92934bb672761320eb7377962b977b39c0e5) )

	NEO_SFIX_128K( "264b1.s1", CRC(b530292a) SHA1(8479cbdb377e7ed324aa777e3f6d094f4d1b80b5) )

	NEO_BIOS_AUDIO_128K( "264nd.m1", CRC(c5d36af9) SHA1(320739d0cfa6cc84455ae1f7b1f9cdab3c018933) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264nd.v1", 0x000000, 0x400000, CRC(5C77A3FE) SHA1(3de61ff174d8b5b1a735666d3ed30554637e4b2d) )
	ROM_LOAD( "264nd.v2", 0x400000, 0x400000, CRC(A9B7AF14) SHA1(5e3c693634139fa8bbc0966af2873d1413cc13d9) )
	ROM_LOAD( "264nd.v3", 0x800000, 0x400000, CRC(17AFF92A) SHA1(cafbef0b1b20b53c9d18c6b727e1912f0c958382) )
	ROM_LOAD( "264nd.v4", 0xC00000, 0x400000, CRC(BC6A091E) SHA1(434b0e7aeac14677c7ce95d119dc1dd7a41a85cb) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264d.c1", 0x0000000, 0x800000, CRC(ec9d18c0) SHA1(83EBEDAE9655B6C64421CD131930B27D252853EC) )
	ROM_LOAD16_BYTE( "264d.c2", 0x0000001, 0x800000, CRC(b1069066) SHA1(0B4E2249EFC782B572B589F72AADBD8007E8778C) )
	ROM_LOAD16_BYTE( "264d.c3", 0x1000000, 0x800000, CRC(7e636d49) SHA1(1BA15DDBCE8369D7232CC1DA3F833F6CB68FBC10) )
	ROM_LOAD16_BYTE( "264d.c4", 0x1000001, 0x800000, CRC(76892fda) SHA1(27416585973A6EC7B5721DE1116C8700B38E3A4C) )
	ROM_LOAD16_BYTE( "264d.c5", 0x2000000, 0x800000, CRC(469061bc) SHA1(34E60E5F93743BE88BFC9E8B7656FE9FAF77F8F5) )
	ROM_LOAD16_BYTE( "264d.c6", 0x2000001, 0x800000, CRC(2200220a) SHA1(8379B4C89854B3CC9B4F33F4F51AB5387ACD14CA) )
	ROM_LOAD16_BYTE( "264d.c7", 0x3000000, 0x800000, CRC(edda4baf) SHA1(3F53EB50FD9EC9E9EE05EEE050885C07023B6D53) )
	ROM_LOAD16_BYTE( "264d.c8", 0x3000001, 0x800000, CRC(82b1ba22) SHA1(B4AD715807F2C15FC06945F0BCB475C3698CF089) )
ROM_END

ROM_START( rotdbr ) /* Rage of the Dragons - Translation Hack by UNKNOWN - (Portuguese translation) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264br.p1", 0x000000, 0x800000, CRC(8f5d7188) SHA1(a29209a05a22e18d6baa78830d6bbc763d23dcac) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdbr1 )
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264br1.p1", 0x000000, 0x800000, CRC(59395cb3) SHA1(3f723a4b9bbc8c587eab449ecdb2be666ca59992) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdbr2 )
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264br2.p1", 0x000000, 0x800000, CRC(8a973ecf) SHA1(5c472fca9091fb88f49ea72ce49b17fae3bbdaa9) )

	NEO_SFIX_128K( "264br2.s1", CRC(28b387d6) SHA1(eb50e74b66ce9e14765fa0841e928b8be3035c73) )

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdbr2d )
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264br2.p1", 0x000000, 0x800000, CRC(8a973ecf) SHA1(5c472fca9091fb88f49ea72ce49b17fae3bbdaa9) )

	NEO_SFIX_128K( "264br2.s1", CRC(28b387d6) SHA1(eb50e74b66ce9e14765fa0841e928b8be3035c73) )

	NEO_BIOS_AUDIO_128K( "264nd.m1", CRC(c5d36af9) SHA1(320739d0cfa6cc84455ae1f7b1f9cdab3c018933) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264nd.v1", 0x000000, 0x400000, CRC(5C77A3FE) SHA1(3de61ff174d8b5b1a735666d3ed30554637e4b2d) )
	ROM_LOAD( "264nd.v2", 0x400000, 0x400000, CRC(A9B7AF14) SHA1(5e3c693634139fa8bbc0966af2873d1413cc13d9) )
	ROM_LOAD( "264nd.v3", 0x800000, 0x400000, CRC(17AFF92A) SHA1(cafbef0b1b20b53c9d18c6b727e1912f0c958382) )
	ROM_LOAD( "264nd.v4", 0xC00000, 0x400000, CRC(BC6A091E) SHA1(434b0e7aeac14677c7ce95d119dc1dd7a41a85cb) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264d.c1", 0x0000000, 0x800000, CRC(ec9d18c0) SHA1(83EBEDAE9655B6C64421CD131930B27D252853EC) )
	ROM_LOAD16_BYTE( "264d.c2", 0x0000001, 0x800000, CRC(b1069066) SHA1(0B4E2249EFC782B572B589F72AADBD8007E8778C) )
	ROM_LOAD16_BYTE( "264d.c3", 0x1000000, 0x800000, CRC(7e636d49) SHA1(1BA15DDBCE8369D7232CC1DA3F833F6CB68FBC10) )
	ROM_LOAD16_BYTE( "264d.c4", 0x1000001, 0x800000, CRC(76892fda) SHA1(27416585973A6EC7B5721DE1116C8700B38E3A4C) )
	ROM_LOAD16_BYTE( "264d.c5", 0x2000000, 0x800000, CRC(469061bc) SHA1(34E60E5F93743BE88BFC9E8B7656FE9FAF77F8F5) )
	ROM_LOAD16_BYTE( "264d.c6", 0x2000001, 0x800000, CRC(2200220a) SHA1(8379B4C89854B3CC9B4F33F4F51AB5387ACD14CA) )
	ROM_LOAD16_BYTE( "264d.c7", 0x3000000, 0x800000, CRC(edda4baf) SHA1(3F53EB50FD9EC9E9EE05EEE050885C07023B6D53) )
	ROM_LOAD16_BYTE( "264d.c8", 0x3000001, 0x800000, CRC(82b1ba22) SHA1(B4AD715807F2C15FC06945F0BCB475C3698CF089) )
ROM_END

ROM_START( rotdcre ) /* Rage of the Dragons - Hack by Creamymami and UNKNOWN - (Console mode enabled - always power max - no change wait) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264cre.p1", 0x000000, 0x800000, CRC(c3f5a8ea) SHA1(4a7beeb4269846f743bafb118256c1106fd7d529) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdcreb ) /* Rage of the Dragons - Hack by Creamymami, UNKNOWN and Ydmis - (Console mode enabled - can choose Abubo and Johann - always power max - no change wait) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264creb.p1", 0x000000, 0x800000, CRC(c058f365) SHA1(84731cf354693141cc06f90a73bbd597eb6a594f) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdd )
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264-p1.p1", 0x000000, 0x800000, CRC(b8cc969d) SHA1(4f2205b4bdd32dd1522106ef4df10ac0eb1b852d) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264d.c1", 0x0000000, 0x800000, CRC(ec9d18c0) SHA1(83EBEDAE9655B6C64421CD131930B27D252853EC) )
	ROM_LOAD16_BYTE( "264d.c2", 0x0000001, 0x800000, CRC(b1069066) SHA1(0B4E2249EFC782B572B589F72AADBD8007E8778C) )
	ROM_LOAD16_BYTE( "264d.c3", 0x1000000, 0x800000, CRC(7e636d49) SHA1(1BA15DDBCE8369D7232CC1DA3F833F6CB68FBC10) )
	ROM_LOAD16_BYTE( "264d.c4", 0x1000001, 0x800000, CRC(76892fda) SHA1(27416585973A6EC7B5721DE1116C8700B38E3A4C) )
	ROM_LOAD16_BYTE( "264d.c5", 0x2000000, 0x800000, CRC(469061bc) SHA1(34E60E5F93743BE88BFC9E8B7656FE9FAF77F8F5) )
	ROM_LOAD16_BYTE( "264d.c6", 0x2000001, 0x800000, CRC(2200220a) SHA1(8379B4C89854B3CC9B4F33F4F51AB5387ACD14CA) )
	ROM_LOAD16_BYTE( "264d.c7", 0x3000000, 0x800000, CRC(edda4baf) SHA1(3F53EB50FD9EC9E9EE05EEE050885C07023B6D53) )
	ROM_LOAD16_BYTE( "264d.c8", 0x3000001, 0x800000, CRC(82b1ba22) SHA1(B4AD715807F2C15FC06945F0BCB475C3698CF089) )
ROM_END

ROM_START( rotdeh ) /* Rage of the Dragons - Hack by Ydmis - (Can choose Abubo and Johann) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264eh.p1", 0x000000, 0x800000, CRC(b8db28bc) SHA1(9fd6cd7a13bde0854243dca4b0d7d9601cde4996) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdehc ) /* Rage of the Dragons - Enhance by Creamymami, FWNL and Ydmis - (Console mode enabled - can choose Abubo and Johann - always power max - no change wait) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264ehc.p1", 0x000000, 0x800000, CRC(2135864c) SHA1(5abd3ffbaf60ebbf7bd15afa0666b959d820c4aa) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdfw ) /* Rage of the Dragons - Hack by FWNL and Ydmis - (Console mode enabled - can choose Abubo and Johann) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264fw.p1", 0x000000, 0x800000, CRC(7b89da35) SHA1(0edc3421f764deac1fefc499ffe469ad30956ebc) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdfy ) /* Rage of the Dragons - Hack by FWNL and Ydmis - (Console mode enabled - can choose Abubo and Johann) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264fy.p1", 0x000000, 0x800000, CRC(4ab52bcd) SHA1(7fcc074fb7c048f824fd5ef9a370c9a908299727) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdh2b ) /* Rage of the Dragons - Hack by UNKNOWN and Ydmis - (Console mode enabled - can choose Abubo and Johann) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264h2b.p1", 0x000000, 0x800000, CRC(87bd2a72) SHA1(5f7ae41b7813fa7058c00cfa1c0d1a8c06395f8a) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdhab ) /* Rage of the Dragons - Hack by HappyAsr - (Console mode enabled - character menue changed - can choose Abubo and Johann - characters choose twice) */
	ROM_REGION( 0x800000, "maincpu", ROMREGION_ERASE00 ) // needed
	ROM_LOAD16_WORD_SWAP( "264hab.p1", 0x000000, 0x300000, CRC(44f5312a) SHA1(9a5356dbde209c9e5ebd04ff025c7c129a0ea4da) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdhab1 )
	ROM_REGION( 0x300000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264hab.p1", 0x000000, 0x300000, CRC(44f5312a) SHA1(9a5356dbde209c9e5ebd04ff025c7c129a0ea4da) )

	NEO_SFIX_128K( "264-s1.bin", CRC(c155d4ff) SHA1(cc20d4e30004ca82da2ba075c084d294c94651d0) )

	NEO_BIOS_AUDIO_128K( "264nd.m1", CRC(c5d36af9) SHA1(320739d0cfa6cc84455ae1f7b1f9cdab3c018933) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264nd.v1", 0x000000, 0x400000, CRC(5C77A3FE) SHA1(3de61ff174d8b5b1a735666d3ed30554637e4b2d) )
	ROM_LOAD( "264nd.v2", 0x400000, 0x400000, CRC(A9B7AF14) SHA1(5e3c693634139fa8bbc0966af2873d1413cc13d9) )
	ROM_LOAD( "264nd.v3", 0x800000, 0x400000, CRC(17AFF92A) SHA1(cafbef0b1b20b53c9d18c6b727e1912f0c958382) )
	ROM_LOAD( "264nd.v4", 0xC00000, 0x400000, CRC(BC6A091E) SHA1(434b0e7aeac14677c7ce95d119dc1dd7a41a85cb) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264d.c1", 0x0000000, 0x800000, CRC(ec9d18c0) SHA1(83EBEDAE9655B6C64421CD131930B27D252853EC) )
	ROM_LOAD16_BYTE( "264d.c2", 0x0000001, 0x800000, CRC(b1069066) SHA1(0B4E2249EFC782B572B589F72AADBD8007E8778C) )
	ROM_LOAD16_BYTE( "264d.c3", 0x1000000, 0x800000, CRC(7e636d49) SHA1(1BA15DDBCE8369D7232CC1DA3F833F6CB68FBC10) )
	ROM_LOAD16_BYTE( "264d.c4", 0x1000001, 0x800000, CRC(76892fda) SHA1(27416585973A6EC7B5721DE1116C8700B38E3A4C) )
	ROM_LOAD16_BYTE( "264d.c5", 0x2000000, 0x800000, CRC(469061bc) SHA1(34E60E5F93743BE88BFC9E8B7656FE9FAF77F8F5) )
	ROM_LOAD16_BYTE( "264d.c6", 0x2000001, 0x800000, CRC(2200220a) SHA1(8379B4C89854B3CC9B4F33F4F51AB5387ACD14CA) )
	ROM_LOAD16_BYTE( "264d.c7", 0x3000000, 0x800000, CRC(edda4baf) SHA1(3F53EB50FD9EC9E9EE05EEE050885C07023B6D53) )
	ROM_LOAD16_BYTE( "264d.c8", 0x3000001, 0x800000, CRC(82b1ba22) SHA1(B4AD715807F2C15FC06945F0BCB475C3698CF089) )
ROM_END

ROM_START( rotdhar ) /* Rage of the Dragons - Hack by HappyAsr - (Console mode enabled) */
	ROM_REGION( 0x800000, "maincpu", ROMREGION_ERASE00 )
	ROM_LOAD16_WORD_SWAP( "264har.p1", 0x000000, 0x300000, CRC(ca979b31) SHA1(03ff383db6b33ffbd7736bc87888f7c645dda62d) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdhfw ) /* Rage of the Dragons - Hack by FWNL - (Console mode enabled) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264hfw.p1", 0x000000, 0x800000, CRC(49187042) SHA1(f7609bc4fa236304bbf7383ea49e2a4a5cf44682) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdhfwb ) /* Rage of the Dragons - Hack by FWNL and Ydmis - (Console mode enabled - can choose Abubo and Johann) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264hfwb.p1", 0x000000, 0x800000, CRC(ed25cd79) SHA1(db73cf2e907fefc7d52cbbda2f36bc5edfa86ccb) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END

ROM_START( rotdnd )
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264-p1.p1", 0x000000, 0x800000, CRC(b8cc969d) SHA1(4f2205b4bdd32dd1522106ef4df10ac0eb1b852d) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_128K( "264nd.m1", CRC(c5d36af9) SHA1(320739d0cfa6cc84455ae1f7b1f9cdab3c018933) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264nd.v1", 0x000000, 0x400000, CRC(5C77A3FE) SHA1(3de61ff174d8b5b1a735666d3ed30554637e4b2d) )
	ROM_LOAD( "264nd.v2", 0x400000, 0x400000, CRC(A9B7AF14) SHA1(5e3c693634139fa8bbc0966af2873d1413cc13d9) )
	ROM_LOAD( "264nd.v3", 0x800000, 0x400000, CRC(17AFF92A) SHA1(cafbef0b1b20b53c9d18c6b727e1912f0c958382) )
	ROM_LOAD( "264nd.v4", 0xC00000, 0x400000, CRC(BC6A091E) SHA1(434b0e7aeac14677c7ce95d119dc1dd7a41a85cb) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264d.c1", 0x0000000, 0x800000, CRC(ec9d18c0) SHA1(83EBEDAE9655B6C64421CD131930B27D252853EC) )
	ROM_LOAD16_BYTE( "264d.c2", 0x0000001, 0x800000, CRC(b1069066) SHA1(0B4E2249EFC782B572B589F72AADBD8007E8778C) )
	ROM_LOAD16_BYTE( "264d.c3", 0x1000000, 0x800000, CRC(7e636d49) SHA1(1BA15DDBCE8369D7232CC1DA3F833F6CB68FBC10) )
	ROM_LOAD16_BYTE( "264d.c4", 0x1000001, 0x800000, CRC(76892fda) SHA1(27416585973A6EC7B5721DE1116C8700B38E3A4C) )
	ROM_LOAD16_BYTE( "264d.c5", 0x2000000, 0x800000, CRC(469061bc) SHA1(34E60E5F93743BE88BFC9E8B7656FE9FAF77F8F5) )
	ROM_LOAD16_BYTE( "264d.c6", 0x2000001, 0x800000, CRC(2200220a) SHA1(8379B4C89854B3CC9B4F33F4F51AB5387ACD14CA) )
	ROM_LOAD16_BYTE( "264d.c7", 0x3000000, 0x800000, CRC(edda4baf) SHA1(3F53EB50FD9EC9E9EE05EEE050885C07023B6D53) )
	ROM_LOAD16_BYTE( "264d.c8", 0x3000001, 0x800000, CRC(82b1ba22) SHA1(B4AD715807F2C15FC06945F0BCB475C3698CF089) )
ROM_END

ROM_START( rotdyc ) /* Rage of the Dragons - Hack by Creamymami and Ydmis - (Console mode enabled - can choose Abubo and Johann - power hack) */
	ROM_REGION( 0x800000, "maincpu", 0 )
	ROM_LOAD16_WORD_SWAP( "264yc.p1", 0x000000, 0x800000, CRC(ff3ef1ab) SHA1(bad86a1c5cdedc2589b7f668e64e10e630574fef) )

	NEO_SFIX_MT_128K

	NEO_BIOS_AUDIO_64K( "264d.m1", CRC(7e06206d) SHA1(ba32dd6ffbfbf532bba9bed4c2d70cfbe959ac23) )

	ROM_REGION( 0x1000000, "ymsnd", 0 )
	ROM_LOAD( "264-v1.v1", 0x000000, 0x800000, CRC(fa005812) SHA1(73723126dab5a640ac11955ed6da1bf7a91394f5) )
	ROM_LOAD( "264-v2.v2", 0x800000, 0x800000, CRC(c3dc8bf0) SHA1(a105e37262d9500a30fb8a5dac05aa4fab2562a3) )

	ROM_REGION( 0x4000000, "sprites", 0 )
	ROM_LOAD16_BYTE( "264-c1.c1", 0x0000000, 0x800000, CRC(4f148fee) SHA1(0821463765fad8fbd0dfbbabb7807337d0333719) )
	ROM_LOAD16_BYTE( "264-c2.c2", 0x0000001, 0x800000, CRC(7cf5ff72) SHA1(ccb2f94bce943576d224cb326806942426d25584) )
	ROM_LOAD16_BYTE( "264-c3.c3", 0x1000000, 0x800000, CRC(64d84c98) SHA1(8faf153f465ce6fb7770b27a7ce63caf11dd4086) )
	ROM_LOAD16_BYTE( "264-c4.c4", 0x1000001, 0x800000, CRC(2f394a95) SHA1(82347e8f2b48b0522d7d91fd3f372d5768934ab2) )
	ROM_LOAD16_BYTE( "264-c5.c5", 0x2000000, 0x800000, CRC(6b99b978) SHA1(8fd0a60029b41668f9e1e3056edd3c90f62efa83) )
	ROM_LOAD16_BYTE( "264-c6.c6", 0x2000001, 0x800000, CRC(847d5c7d) SHA1(a2ce03f6302edf81f2645de9ec61df1a281ddd78) )
	ROM_LOAD16_BYTE( "264-c7.c7", 0x3000000, 0x800000, CRC(231d681e) SHA1(87836e64dc816f8bf1c834641535ea96baacc024) )
	ROM_LOAD16_BYTE( "264-c8.c8", 0x3000001, 0x800000, CRC(c5edb5c4) SHA1(253378c8739daa5da4edb15eff7050820b2b3755) )
ROM_END



GAME( 2002, rotdb,     rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "Ydmis", "Rage of the Dragons (Add Char - Console mode enabled set 4)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann
GAME( 2002, rotdbr,    rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "hack", "Rage of the Dragons (Portuguese)", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdbr1,   rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "hack", "Rage of the Dragons (Portuguese) (Alt Set 1)", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdbr2,   rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "hack", "Rage of the Dragons (Portuguese) (Alt Set 2)", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdcre,   rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "Creamymami and Unk","Rage of the Dragons (Console mode enabled - Always pow max - No change wait)", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdcreb,  rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "Creamymami, Unk and Ydmis","Rage of the Dragons (Add Char - Console mode enabled - Always pow max - No change wait set 2)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann
GAME( 2002, rotdd,     rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdd, ROT0, "Evoga / Playmore","Rage of the Dragons (decrypted C)", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdeh,    rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "Ydmis", "Rage of the Dragons (Add Char)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann
GAME( 2002, rotdehc,   rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "Creamymami, FWNL and Ydmis","Rage of the Dragons (Add Char - Console mode enabled - Always pow max - No change wait set 1)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann
GAME( 2002, rotdfw,    rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "FWNL and Ydmis", "Rage of the Dragons (Add Char - Console mode enabled set 2)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann
GAME( 2002, rotdfy,    rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "FWNL and Ydmis", "Rage of the Dragons (Add Char - Console mode enabled set 3)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann
GAME( 2002, rotdh2b,   rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "Unk and Ydmis", "Rage of the Dragons (Add Char - Console mode enabled set 5)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann
GAME( 2002, rotdhab,   rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "HappyAsr", "Rage of the Dragons (Add Char - Console mode enabled - Char menu changed - Char choose twice)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann
GAME( 2002, rotdhar,   rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "HappyAsr", "Rage of the Dragons (Console mode enabled set 1)", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdhfw,   rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "FWNL", "Rage of the Dragons (Console mode enabled set 2)", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdhfwb,  rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "FWNL and Ydmis", "Rage of the Dragons (Add Char - Console mode enabled set 1)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann
GAME( 2002, rotdyc,    rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdb, ROT0, "Creamymami and Ydmis", "Rage of the Dragons (Add Char - Console mode enabled - Pow hack)", MACHINE_SUPPORTS_SAVE ) // Abubo and Johann



GAME( 2002, rotdbr2d,  rotd, neogeo_noslot, neogeo, neogeo_state,  neogeo, ROT0, "hack", "Rage of the Dragons - Portuguese/Brazilian Hack ver 2.0", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdb1,    rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdnd, ROT0, "hack", "Rage of the Dragons (Boss Hack)2", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdhab1,  rotd, neogeo_noslot, neogeo, neogeo_state,  neogeo, ROT0, "hack", "Rage of the Dragons (Hack, Hero AES) [EGCG]", MACHINE_SUPPORTS_SAVE )
GAME( 2002, rotdnd,    rotd, neogeo_noslot, neogeo, neogeo_hbmame, rotdnd, ROT0, "Evoga / Playmore Corporation", "Rage of the Dragons (decrypted V,decrypted C)", MACHINE_SUPPORTS_SAVE )
