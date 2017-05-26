// license:BSD-3-Clause
// copyright-holders:Vas Crabb

#include "audio/nl_cheekyms.h"
#include "netlist/devices/net_lib.h"


#ifndef __PLIB_PREPROCESSOR__

#endif


NETLIST_START(cheekyms_schematics)

	// Shared chips
	TTL_7404_DIP(IC1)
	LM324_DIP(IC5)
	NET_C(IC1.14, IC5.4, I_V5.Q)
	NET_C(IC1.7, IC5.11, GND)

	// shut the netlist parser up about unconnected inputs
	NET_C(I_V5.Q, IC1.11, IC1.13)

	// Mute
	RES(R1, RES_K(10))
	CAP(C10, CAP_U(10))
	QBJT_EB(Q1, "2SC945")
	NET_C(IC1.2, R1.1)
	NET_C(R1.2, C10.1, Q1.B)
	NET_C(C10.2, Q1.E, GND)

	// Cheese
#if 0
	// FIXME: Not working right, causes the netlist system to die
	// Note that the collector of Q2 is not connected, they're just using the base-emitter junction as a diode
	// Well, either that or there's an error in the schematic
	RES(R2, RES_M(1))
	RES(R3, RES_K(1))
	RES(R4, RES_K(100))
	RES(R5, RES_K(1))
	RES(R6, RES_K(100))
	RES(R7, RES_K(1))
	RES(R8, RES_M(1))
	RES(R9, RES_K(10))
	RES(R10, RES_K(10))
	RES(R11, RES_K(10))
	RES(R12, RES_K(100))
	CAP(C8, CAP_U(0.1))
	CAP(C9, CAP_U(0.1))
	CAP(C11, CAP_U(0.1))
	QBJT_EB(Q2, "2SC945")
	NET_C(R2.1, I_VPLUS.Q)
	NET_C(R2.2, C8.1, Q2.E)
	NET_C(R3.1, C8.2)
	NET_C(R3.2, R4.1, IC5.10)
	NET_C(R5.2, R6.1, IC5.9)
	NET_C(R6.2, C9.1, IC5.8)
	NET_C(R7.1, C9.2)
	NET_C(R7.2, R8.1, IC5.13)
	NET_C(R8.2, C11.1, IC5.14)
	NET_C(R10.2, IC1.4)
	NET_C(R9.1, R10.1, IC5.12)
	NET_C(R9.2, I_V5.Q)
	NET_C(R11.1, R12.1, C11.2)
	NET_C(R4.2, R5.1, R11.2, Q2.B, GND)
#else
	// Rip out just enough to make it not blow up
	RES(R4, RES_K(100))
	RES(R5, RES_K(1))
	RES(R6, RES_K(100))
	RES(R7, RES_K(1))
	RES(R8, RES_M(1))
	RES(R9, RES_K(10))
	RES(R10, RES_K(10))
	RES(R11, RES_K(10))
	RES(R12, RES_K(100))
	CAP(C9, CAP_U(0.1))
	CAP(C11, CAP_U(0.1))
	NET_C(R4.1, IC5.10)
	NET_C(R5.2, R6.1, IC5.9)
	NET_C(R6.2, C9.1, IC5.8)
	NET_C(R7.1, C9.2)
	NET_C(R7.2, R8.1, IC5.13)
	NET_C(R8.2, C11.1, IC5.14)
	NET_C(R10.1, IC1.4)
	NET_C(R9.1, R10.2, IC5.12)
	NET_C(R9.2, I_V5.Q)
	NET_C(R11.1, R12.1, C11.2)
	NET_C(R4.2, R5.1, R11.2, GND)
#endif

	// Music
	RES(R13, RES_K(100))

	// Mouse
	RES(R14, RES_K(4.7))
	RES(R15, RES_K(1))
	RES(R16, RES_K(68))
	RES(R17, RES_K(100))
	CAP(C12, CAP_U(0.01))
	CAP(C13, CAP_U(10))
	DIODE(D4, "1S1588")
	NE555(IC4_1) // one half of a 556 (other half does coin & extra)
	NET_C(D4.K, R14.1, IC4_1.RESET)
	NET_C(D4.A, R14.2, C13.1, IC4_1.CONT)
	NET_C(R15.1, IC4_1.VCC, I_V5.Q)
	NET_C(R15.2, R16.1, IC4_1.DISCH)
	NET_C(R16.2, C12.1, IC4_1.TRIG, IC4_1.THRESH)
	NET_C(C13.2, C12.2, IC4_1.GND, GND)
	NET_C(R17.1, IC4_1.OUT)

	// Hammer
	RES(R18, RES_K(1))
	RES(R19, RES_K(150))
	RES(R20, RES_K(10))
	RES(R21, RES_K(100))
	RES(R22, RES_K(100))
	RES(R23, RES_M(1))
	RES(R24, RES_K(51))
	CAP(C14, CAP_U(0.01))
	CAP(C15, CAP_U(0.01))
	CAP(C16, CAP_U(0.1))
	DIODE(D5, "1S1588")
	DIODE(D6, "1S1588")
	NE555(IC6_1) // one half of a 556 (other half does pest)
	NET_C(R18.1, R23.1, IC6_1.RESET, IC6_1.VCC, I_V5.Q)
	NET_C(R18.2, R19.1, IC6_1.DISCH)
	NET_C(R19.2, C14.1, IC6_1.TRIG, IC6_1.THRESH)
	NET_C(R20.1, IC6_1.OUT)
	NET_C(R20.2, R21.1, C15.1)
	NET_C(R21.2, R22.1, IC5.6)
	NET_C(R22.2, R24.1, IC5.7)
	NET_C(D5.K, IC1.6)
	NET_C(D5.A, D6.K)
	NET_C(R23.2, C16.1, D6.A, IC5.5)
	NET_C(C14.2, C15.2, C16.2, IC6_1.GND, GND)

	// Pest
	RES(R25, RES_K(20))
	RES(R26, RES_K(10))
	RES(R27, 220)
	RES(R28, RES_K(100))
	RES(R29, RES_K(4.7))
	RES(R30, RES_K(1))
	RES(R31, RES_K(68))
	RES(R32, RES_K(100))
	RES(R33, RES_K(100))
	RES(R34, RES_K(51))
	RES(R35, RES_M(1))
	CAP(C17, CAP_U(2.2))
	CAP(C18, CAP_U(10))
	CAP(C19, CAP_U(0.01))
	CAP(C20, CAP_U(0.22))
	DIODE(D7, "1S1588")
	DIODE(D8, "1S1588")
	DIODE(D9, "1S1588")
	NE555(IC3)
	NE555(IC6_2) // one half of a 556 (other half does hammer)
	NET_C(R25.1, R29.1, R30.1, R35.2, IC3.RESET, IC3.VCC, IC6_2.RESET, IC6_2.VCC, I_V5.Q)
	NET_C(R25.2, R26.1, IC3.DISCH)
	NET_C(R26.2, C17.1, IC3.TRIG, IC3.THRESH)
	NET_C(R27.1, R28.1, IC3.OUT)
	NET_C(R27.2, D7.K)
	NET_C(R28.2, R29.2, C18.1, D7.A, IC6_2.CONT)
	NET_C(R30.2, R31.1, IC6_2.DISCH)
	NET_C(R31.2, C19.1, IC6_2.TRIG, IC6_2.THRESH)
	NET_C(R32.1, IC6_2.OUT)
	NET_C(R32.2, R33.1, IC5.2)
	NET_C(R33.2, R34.1, IC5.1)
	NET_C(D8.K, IC1.8)
	NET_C(D8.A, D9.K)
	NET_C(R35.1, C20.1, D9.A, IC5.3)
	NET_C(C17.2, C18.2, C19.2, C20.2, IC3.GND, IC6_2.GND, GND)

	// Mouse dies
	RES(R36, RES_K(1))
	RES(R37, RES_K(33))
	RES(R38, 560)
	RES(R39, RES_K(100))
	CAP(C21, CAP_U(0.01))
	CAP(C22, CAP_U(47))
	NE555(IC2_2) // one half of a 556 (other half does pest dies)
	NET_C(R38.1, IC2_2.RESET)
	NET_C(R38.2, C22.1, IC2_2.CONT)
	NET_C(R36.1, IC2_2.VCC, I_V5.Q)
	NET_C(R36.2, R37.1, IC2_2.DISCH)
	NET_C(R37.2, C21.1, IC2_2.TRIG, IC2_2.THRESH)
	NET_C(C22.2, C21.2, IC2_2.GND, GND)
	NET_C(R39.1, IC2_2.OUT)

	// Pest dies
	RES(R40, RES_K(1))
	RES(R41, RES_K(47))
	RES(R42, RES_K(100))
	CAP(C23, CAP_U(0.033))
	NE555(IC2_1) // one half of a 556 (other half does mouse dies)
	NET_C(R40.1, IC2_1.VCC, I_V5.Q)
	NET_C(R40.2, R41.1, IC2_1.DISCH)
	NET_C(R41.2, C23.1, IC2_1.TRIG, IC2_1.THRESH)
	NET_C(C23.2, IC2_1.GND, GND)
	NET_C(R42.1, IC2_1.OUT)

	// Coin & extra
	RES(R44, RES_K(1))
	RES(R45, RES_K(47))
	RES(R46, RES_K(100))
	CAP(C24, CAP_U(0.01))
	NE555(IC4_2) // one half of a 556 (other half does mouse)
	NET_C(R44.1, IC4_2.VCC, I_V5.Q)
	NET_C(R44.2, R45.1, IC4_2.DISCH)
	NET_C(R45.2, C24.1, IC4_2.TRIG, IC4_2.THRESH)
	NET_C(C24.2, IC4_2.GND, GND)
	NET_C(R46.1, IC4_2.OUT)

	// Mixdown
	RES(R43, RES_K(10))
	POT(VR1, RES_K(1))
	NET_C(R12.2, R13.2, R17.2, R24.2, R34.2, R39.2, R42.2, R43.1, Q1.C)
	NET_C(R46.2, R43.2, VR1.1)
	NET_C(VR1.3, GND)

NETLIST_END()


NETLIST_START(cheekyms)

	SOLVER(Solver, 180000)
	PARAM(Solver.ACCURACY, 1e-8)
	PARAM(Solver.NR_LOOPS, 300)
	PARAM(Solver.GS_LOOPS, 1)
	PARAM(Solver.METHOD, "MAT_CR")
	PARAM(Solver.PARALLEL, 0)
	PARAM(Solver.SOR_FACTOR, 1.00)
	PARAM(Solver.DYNAMIC_TS, 0)
	PARAM(Solver.DYNAMIC_LTE, 5e-4)
	PARAM(Solver.DYNAMIC_MIN_TIMESTEP, 20e-6)

	LOCAL_SOURCE(cheekyms_schematics)

	ANALOG_INPUT(I_V5, 5)
	ANALOG_INPUT(I_VPLUS, 12.9) // very approximate - 15V dropped by three diodes and filtered
	//ANALOG_INPUT(I_V0, 0)
	ALIAS(I_V0.Q, GND)

	INCLUDE(cheekyms_schematics)

	LOGIC_INPUT(I_MUTE,       1, "74XX") // FIXME: need 74LS family model (half the sink capability)
	LOGIC_INPUT(I_CHEESE,     1, "74XX") // FIXME: need 74LS family model (half the sink capability)
	LOGIC_INPUT(I_MUSIC,      1, "74XX") // FIXME: need 74LS family model (half the sink capability)
	LOGIC_INPUT(I_MOUSE,      1, "74XX") // FIXME: need 74LS family model (half the sink capability)
	LOGIC_INPUT(I_HAMMER,     1, "74XX") // FIXME: need 74LS family model (half the sink capability)
	LOGIC_INPUT(I_PEST,       1, "74XX") // FIXME: need 74LS family model (half the sink capability)
	LOGIC_INPUT(I_MOUSE_DIES, 1, "74XX") // FIXME: need 74LS family model (half the sink capability)
	LOGIC_INPUT(I_PEST_DIES,  1, "74XX") // FIXME: need 74LS family model (half the sink capability)
	LOGIC_INPUT(I_COIN_EXTRA, 1, "74XX") // FIXME: need 74LS family model (half the sink capability)
	NET_C(I_MUTE.Q,       IC1.1)
	NET_C(I_CHEESE.Q,     IC1.3)
	NET_C(I_MUSIC.Q,      R13.1)
	NET_C(I_MOUSE.Q,      IC4_1.RESET)
	NET_C(I_HAMMER.Q,     IC1.5)
	NET_C(I_PEST.Q,       IC1.9)
	NET_C(I_MOUSE_DIES.Q, IC2_2.RESET)
	NET_C(I_PEST_DIES.Q,  IC2_1.RESET)
	NET_C(I_COIN_EXTRA.Q, IC4_2.RESET)

NETLIST_END()
