<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="sense_pcb_components">
<packages>
<package name="FUSE_PADS">
<smd name="P$1" x="0" y="0" dx="2.8" dy="2" layer="16"/>
<smd name="P$2" x="0" y="8.35" dx="2.8" dy="2" layer="16"/>
<smd name="P$3" x="0" y="0" dx="2.8" dy="2" layer="1"/>
<smd name="P$4" x="0" y="8.35" dx="2.8" dy="2" layer="1"/>
<pad name="P$5" x="0" y="0.508" drill="0.3048" shape="square"/>
<pad name="P$6" x="0" y="7.842" drill="0.3048" shape="square"/>
</package>
<package name="CON18_2X9_UF_DF11_HIR">
<pad name="1" x="0" y="0" drill="0.762" diameter="1.27"/>
<pad name="2" x="0" y="2.0066" drill="0.762" diameter="1.27"/>
<pad name="3" x="-2.0066" y="0" drill="0.762" diameter="1.27"/>
<pad name="4" x="-2.0066" y="2.0066" drill="0.762" diameter="1.27"/>
<pad name="5" x="-3.9878" y="0" drill="0.762" diameter="1.27"/>
<pad name="6" x="-3.9878" y="2.0066" drill="0.762" diameter="1.27"/>
<pad name="7" x="-5.9944" y="0" drill="0.762" diameter="1.27"/>
<pad name="8" x="-5.9944" y="2.0066" drill="0.762" diameter="1.27"/>
<pad name="9" x="-8.001" y="0" drill="0.762" diameter="1.27"/>
<pad name="10" x="-8.001" y="2.0066" drill="0.762" diameter="1.27"/>
<pad name="11" x="-10.0076" y="0" drill="0.762" diameter="1.27"/>
<pad name="12" x="-10.0076" y="2.0066" drill="0.762" diameter="1.27"/>
<pad name="13" x="-11.9888" y="0" drill="0.762" diameter="1.27"/>
<pad name="14" x="-11.9888" y="2.0066" drill="0.762" diameter="1.27"/>
<pad name="15" x="-13.9954" y="0" drill="0.762" diameter="1.27"/>
<pad name="16" x="-13.9954" y="2.0066" drill="0.762" diameter="1.27"/>
<pad name="17" x="-16.002" y="0" drill="0.762" diameter="1.27"/>
<pad name="18" x="-16.002" y="2.0066" drill="0.762" diameter="1.27"/>
<wire x1="-2.0066" y1="0" x2="-2.0066" y2="5.6642" width="0.1524" layer="47"/>
<wire x1="-2.0066" y1="5.6642" x2="-2.0066" y2="6.0452" width="0.1524" layer="47"/>
<wire x1="0" y1="0" x2="0" y2="2.0066" width="0.1524" layer="47"/>
<wire x1="0" y1="2.0066" x2="0" y2="5.6642" width="0.1524" layer="47"/>
<wire x1="0" y1="5.6642" x2="0" y2="6.0452" width="0.1524" layer="47"/>
<wire x1="-2.0066" y1="5.6642" x2="-3.2766" y2="5.6642" width="0.1524" layer="47"/>
<wire x1="0" y1="5.6642" x2="1.27" y2="5.6642" width="0.1524" layer="47"/>
<wire x1="-2.0066" y1="5.6642" x2="-2.2606" y2="5.7912" width="0.1524" layer="47"/>
<wire x1="-2.0066" y1="5.6642" x2="-2.2606" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="-2.2606" y1="5.7912" x2="-2.2606" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="0" y1="5.6642" x2="0.254" y2="5.7912" width="0.1524" layer="47"/>
<wire x1="0" y1="5.6642" x2="0.254" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="0.254" y1="5.7912" x2="0.254" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="-18.0086" y1="3.5052" x2="-18.0086" y2="13.9192" width="0.1524" layer="47"/>
<wire x1="-18.0086" y1="13.9192" x2="-18.0086" y2="14.3002" width="0.1524" layer="47"/>
<wire x1="2.0066" y1="3.5052" x2="2.0066" y2="13.9192" width="0.1524" layer="47"/>
<wire x1="2.0066" y1="13.9192" x2="2.0066" y2="14.3002" width="0.1524" layer="47"/>
<wire x1="-18.0086" y1="13.9192" x2="2.0066" y2="13.9192" width="0.1524" layer="47"/>
<wire x1="-18.0086" y1="13.9192" x2="-17.7546" y2="14.0462" width="0.1524" layer="47"/>
<wire x1="-18.0086" y1="13.9192" x2="-17.7546" y2="13.7922" width="0.1524" layer="47"/>
<wire x1="-17.7546" y1="14.0462" x2="-17.7546" y2="13.7922" width="0.1524" layer="47"/>
<wire x1="2.0066" y1="13.9192" x2="1.7526" y2="14.0462" width="0.1524" layer="47"/>
<wire x1="2.0066" y1="13.9192" x2="1.7526" y2="13.7922" width="0.1524" layer="47"/>
<wire x1="1.7526" y1="14.0462" x2="1.7526" y2="13.7922" width="0.1524" layer="47"/>
<wire x1="0" y1="2.0066" x2="4.5466" y2="2.0066" width="0.1524" layer="47"/>
<wire x1="4.5466" y1="2.0066" x2="4.9276" y2="2.0066" width="0.1524" layer="47"/>
<wire x1="0" y1="0" x2="4.5466" y2="0" width="0.1524" layer="47"/>
<wire x1="4.5466" y1="0" x2="4.9276" y2="0" width="0.1524" layer="47"/>
<wire x1="4.5466" y1="2.0066" x2="4.5466" y2="3.2766" width="0.1524" layer="47"/>
<wire x1="4.5466" y1="0" x2="4.5466" y2="-1.27" width="0.1524" layer="47"/>
<wire x1="4.5466" y1="2.0066" x2="4.4196" y2="2.2606" width="0.1524" layer="47"/>
<wire x1="4.5466" y1="2.0066" x2="4.6736" y2="2.2606" width="0.1524" layer="47"/>
<wire x1="4.4196" y1="2.2606" x2="4.6736" y2="2.2606" width="0.1524" layer="47"/>
<wire x1="4.5466" y1="0" x2="4.4196" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="4.5466" y1="0" x2="4.6736" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="4.4196" y1="-0.254" x2="4.6736" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="-27.1526" y1="3.5052" x2="-27.5336" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="-8.001" y1="0.9906" x2="-27.1526" y2="0.9906" width="0.1524" layer="47"/>
<wire x1="-27.1526" y1="0.9906" x2="-27.5336" y2="0.9906" width="0.1524" layer="47"/>
<wire x1="-27.1526" y1="3.5052" x2="-27.1526" y2="4.7752" width="0.1524" layer="47"/>
<wire x1="-27.1526" y1="0.9906" x2="-27.1526" y2="-0.2794" width="0.1524" layer="47"/>
<wire x1="-27.1526" y1="3.5052" x2="-27.2796" y2="3.7592" width="0.1524" layer="47"/>
<wire x1="-27.1526" y1="3.5052" x2="-27.0256" y2="3.7592" width="0.1524" layer="47"/>
<wire x1="-27.2796" y1="3.7592" x2="-27.0256" y2="3.7592" width="0.1524" layer="47"/>
<wire x1="-27.1526" y1="0.9906" x2="-27.2796" y2="0.7366" width="0.1524" layer="47"/>
<wire x1="-27.1526" y1="0.9906" x2="-27.0256" y2="0.7366" width="0.1524" layer="47"/>
<wire x1="-27.2796" y1="0.7366" x2="-27.0256" y2="0.7366" width="0.1524" layer="47"/>
<wire x1="-18.0086" y1="3.5052" x2="-25.8826" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="-25.8826" y1="3.5052" x2="-27.1526" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="-18.0086" y1="-1.4986" x2="-25.8826" y2="-1.4986" width="0.1524" layer="47"/>
<wire x1="-25.8826" y1="-1.4986" x2="-26.2636" y2="-1.4986" width="0.1524" layer="47"/>
<wire x1="-25.8826" y1="3.5052" x2="-25.8826" y2="-1.4986" width="0.1524" layer="47"/>
<wire x1="-25.8826" y1="3.5052" x2="-26.0096" y2="3.2512" width="0.1524" layer="47"/>
<wire x1="-25.8826" y1="3.5052" x2="-25.7556" y2="3.2512" width="0.1524" layer="47"/>
<wire x1="-26.0096" y1="3.2512" x2="-25.7556" y2="3.2512" width="0.1524" layer="47"/>
<wire x1="-25.8826" y1="-1.4986" x2="-26.0096" y2="-1.2446" width="0.1524" layer="47"/>
<wire x1="-25.8826" y1="-1.4986" x2="-25.7556" y2="-1.2446" width="0.1524" layer="47"/>
<wire x1="-26.0096" y1="-1.2446" x2="-25.7556" y2="-1.2446" width="0.1524" layer="47"/>
<text x="-23.7744" y="-5.5626" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: EX50Y50D30P</text>
<text x="-23.9776" y="-7.4676" size="1.27" layer="47" ratio="6" rot="SR0">1st Mtg Padstyle: RX110Y79D0T</text>
<text x="-24.1554" y="-9.3726" size="1.27" layer="47" ratio="6" rot="SR0">2nd Mtg Padstyle: EX70Y70D70P</text>
<text x="-24.1554" y="-11.2776" size="1.27" layer="47" ratio="6" rot="SR0">3rd Mtg Padstyle: EX70Y70D70P</text>
<text x="-24.3586" y="-13.1826" size="1.27" layer="47" ratio="6" rot="SR0">Left Mtg Padstyle: EX60Y60D30P</text>
<text x="-24.9428" y="-15.0876" size="1.27" layer="47" ratio="6" rot="SR0">Right Mtg Padstyle: EX60Y60D30P</text>
<text x="-22.8092" y="-16.9926" size="1.27" layer="47" ratio="6" rot="SR0">Alt Padstyle 1: OX60Y90D30P</text>
<text x="-22.8092" y="-18.8976" size="1.27" layer="47" ratio="6" rot="SR0">Alt Padstyle 2: OX90Y60D30P</text>
<text x="-1.9812" y="6.1722" size="0.635" layer="47" ratio="4" rot="SR0">0.079in/2mm</text>
<text x="-11.2776" y="14.4272" size="0.635" layer="47" ratio="4" rot="SR0">0.787in/20mm</text>
<text x="5.0546" y="0.6858" size="0.635" layer="47" ratio="4" rot="SR0">0.079in/2mm</text>
<text x="-34.5948" y="1.9304" size="0.635" layer="47" ratio="4" rot="SR0">0.098in/2.5mm</text>
<text x="-32.3596" y="0.6858" size="0.635" layer="47" ratio="4" rot="SR0">0.197in/5mm</text>
<wire x1="-18.1356" y1="-1.6256" x2="2.1336" y2="-1.6256" width="0.1524" layer="21"/>
<wire x1="2.1336" y1="-1.6256" x2="2.1336" y2="3.6322" width="0.1524" layer="21"/>
<wire x1="2.1336" y1="3.6322" x2="-18.1356" y2="3.6322" width="0.1524" layer="21"/>
<wire x1="-18.1356" y1="3.6322" x2="-18.1356" y2="-1.6256" width="0.1524" layer="21"/>
<wire x1="3.1496" y1="0" x2="2.3876" y2="0" width="0.508" layer="21" curve="-180"/>
<wire x1="2.3876" y1="0" x2="3.1496" y2="0" width="0.508" layer="21" curve="-180"/>
<wire x1="-18.0086" y1="-1.4986" x2="2.0066" y2="-1.4986" width="0.1524" layer="51"/>
<wire x1="2.0066" y1="-1.4986" x2="2.0066" y2="3.5052" width="0.1524" layer="51"/>
<wire x1="2.0066" y1="3.5052" x2="-18.0086" y2="3.5052" width="0.1524" layer="51"/>
<wire x1="-18.0086" y1="3.5052" x2="-18.0086" y2="-1.4986" width="0.1524" layer="51"/>
<wire x1="0.381" y1="-1.905" x2="-0.381" y2="-1.905" width="0.508" layer="51" curve="-180"/>
<wire x1="-0.381" y1="-1.905" x2="0.381" y2="-1.905" width="0.508" layer="51" curve="-180"/>
<wire x1="3.1496" y1="0" x2="2.3876" y2="0" width="0.508" layer="22" curve="-180"/>
<wire x1="2.3876" y1="0" x2="3.1496" y2="0" width="0.508" layer="22" curve="-180"/>
<text x="-11.2776" y="0.3556" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-9.7282" y="0.3556" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
</package>
<package name="BB_CONTACT">
<smd name="P$1" x="0" y="0" dx="5" dy="4" layer="1"/>
</package>
<package name="THERM_PIN">
<smd name="P$1" x="0" y="0" dx="1.27" dy="0.2794" layer="1" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="FUSE">
<pin name="P$1" x="10.16" y="0" length="middle"/>
<pin name="P$2" x="2.54" y="0" length="middle" rot="R180"/>
<wire x1="2.54" y1="2.54" x2="10.16" y2="2.54" width="0.254" layer="94"/>
<wire x1="10.16" y1="2.54" x2="10.16" y2="-2.54" width="0.254" layer="94"/>
<wire x1="10.16" y1="-2.54" x2="2.54" y2="-2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="2.54" y2="2.54" width="0.254" layer="94"/>
<text x="4.064" y="-0.508" size="1.27" layer="94">FUSE</text>
</symbol>
<symbol name="CON18_2X9_UF_DF11">
<pin name="1" x="0" y="0" visible="pad" length="middle" direction="pas"/>
<pin name="2" x="0" y="-2.54" visible="pad" length="middle" direction="pas"/>
<pin name="3" x="0" y="-5.08" visible="pad" length="middle" direction="pas"/>
<pin name="4" x="0" y="-7.62" visible="pad" length="middle" direction="pas"/>
<pin name="5" x="0" y="-10.16" visible="pad" length="middle" direction="pas"/>
<pin name="6" x="0" y="-12.7" visible="pad" length="middle" direction="pas"/>
<pin name="7" x="0" y="-15.24" visible="pad" length="middle" direction="pas"/>
<pin name="8" x="0" y="-17.78" visible="pad" length="middle" direction="pas"/>
<pin name="9" x="0" y="-20.32" visible="pad" length="middle" direction="pas"/>
<pin name="10" x="0" y="-22.86" visible="pad" length="middle" direction="pas"/>
<pin name="11" x="0" y="-25.4" visible="pad" length="middle" direction="pas"/>
<pin name="12" x="0" y="-27.94" visible="pad" length="middle" direction="pas"/>
<pin name="13" x="0" y="-30.48" visible="pad" length="middle" direction="pas"/>
<pin name="14" x="0" y="-33.02" visible="pad" length="middle" direction="pas"/>
<pin name="15" x="0" y="-35.56" visible="pad" length="middle" direction="pas"/>
<pin name="16" x="0" y="-38.1" visible="pad" length="middle" direction="pas"/>
<pin name="17" x="0" y="-40.64" visible="pad" length="middle" direction="pas"/>
<pin name="18" x="0" y="-43.18" visible="pad" length="middle" direction="pas"/>
<wire x1="10.16" y1="0" x2="5.08" y2="0" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-2.54" x2="5.08" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-5.08" x2="5.08" y2="-5.08" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-7.62" x2="5.08" y2="-7.62" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-10.16" x2="5.08" y2="-10.16" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-12.7" x2="5.08" y2="-12.7" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-15.24" x2="5.08" y2="-15.24" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-17.78" x2="5.08" y2="-17.78" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-20.32" x2="5.08" y2="-20.32" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-22.86" x2="5.08" y2="-22.86" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-25.4" x2="5.08" y2="-25.4" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-27.94" x2="5.08" y2="-27.94" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-30.48" x2="5.08" y2="-30.48" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-33.02" x2="5.08" y2="-33.02" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-35.56" x2="5.08" y2="-35.56" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-38.1" x2="5.08" y2="-38.1" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-40.64" x2="5.08" y2="-40.64" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-43.18" x2="5.08" y2="-43.18" width="0.1524" layer="94"/>
<wire x1="10.16" y1="0" x2="8.89" y2="0.8382" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-2.54" x2="8.89" y2="-1.7018" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-5.08" x2="8.89" y2="-4.2418" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-7.62" x2="8.89" y2="-6.7818" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-10.16" x2="8.89" y2="-9.3218" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-12.7" x2="8.89" y2="-11.8618" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-15.24" x2="8.89" y2="-14.4018" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-17.78" x2="8.89" y2="-16.9418" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-20.32" x2="8.89" y2="-19.4818" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-22.86" x2="8.89" y2="-22.0218" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-25.4" x2="8.89" y2="-24.5618" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-27.94" x2="8.89" y2="-27.1018" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-30.48" x2="8.89" y2="-29.6418" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-33.02" x2="8.89" y2="-32.1818" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-35.56" x2="8.89" y2="-34.7218" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-38.1" x2="8.89" y2="-37.2618" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-40.64" x2="8.89" y2="-39.8018" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-43.18" x2="8.89" y2="-42.3418" width="0.1524" layer="94"/>
<wire x1="10.16" y1="0" x2="8.89" y2="-0.8382" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-2.54" x2="8.89" y2="-3.3782" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-5.08" x2="8.89" y2="-5.9182" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-7.62" x2="8.89" y2="-8.4582" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-10.16" x2="8.89" y2="-10.9982" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-12.7" x2="8.89" y2="-13.5382" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-15.24" x2="8.89" y2="-16.0782" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-17.78" x2="8.89" y2="-18.6182" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-20.32" x2="8.89" y2="-21.1582" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-22.86" x2="8.89" y2="-23.6982" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-25.4" x2="8.89" y2="-26.2382" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-27.94" x2="8.89" y2="-28.7782" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-30.48" x2="8.89" y2="-31.3182" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-33.02" x2="8.89" y2="-33.8582" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-35.56" x2="8.89" y2="-36.3982" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-38.1" x2="8.89" y2="-38.9382" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-40.64" x2="8.89" y2="-41.4782" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-43.18" x2="8.89" y2="-44.0182" width="0.1524" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-45.72" width="0.1524" layer="94"/>
<wire x1="5.08" y1="-45.72" x2="12.7" y2="-45.72" width="0.1524" layer="94"/>
<wire x1="12.7" y1="-45.72" x2="12.7" y2="2.54" width="0.1524" layer="94"/>
<wire x1="12.7" y1="2.54" x2="5.08" y2="2.54" width="0.1524" layer="94"/>
<text x="4.1656" y="5.3086" size="2.0828" layer="95" ratio="6" rot="SR0">&gt;Name</text>
</symbol>
<symbol name="PIN">
<pin name="P$1" x="0" y="0" length="middle"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="FUSE">
<gates>
<gate name="G$1" symbol="FUSE" x="-6.35" y="0"/>
</gates>
<devices>
<device name="" package="FUSE_PADS">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1 P$3 P$5"/>
<connect gate="G$1" pin="P$2" pad="P$2 P$4 P$6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="DF11-18DP-2DSA(24)" prefix="J">
<gates>
<gate name="A" symbol="CON18_2X9_UF_DF11" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CON18_2X9_UF_DF11_HIR">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="10" pad="10"/>
<connect gate="A" pin="11" pad="11"/>
<connect gate="A" pin="12" pad="12"/>
<connect gate="A" pin="13" pad="13"/>
<connect gate="A" pin="14" pad="14"/>
<connect gate="A" pin="15" pad="15"/>
<connect gate="A" pin="16" pad="16"/>
<connect gate="A" pin="17" pad="17"/>
<connect gate="A" pin="18" pad="18"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
<connect gate="A" pin="8" pad="8"/>
<connect gate="A" pin="9" pad="9"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="DF11-18DP-2DSA(24)" constant="no"/>
<attribute name="MFR_NAME" value="Hirose" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="BB_CONTACT">
<gates>
<gate name="G$1" symbol="PIN" x="0" y="0"/>
</gates>
<devices>
<device name="" package="BB_CONTACT">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="THERM_PIN">
<gates>
<gate name="G$1" symbol="PIN" x="0" y="0"/>
</gates>
<devices>
<device name="" package="THERM_PIN">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="sense_pcb_components" deviceset="FUSE" device=""/>
<part name="U$2" library="sense_pcb_components" deviceset="FUSE" device=""/>
<part name="U$3" library="sense_pcb_components" deviceset="FUSE" device=""/>
<part name="U$4" library="sense_pcb_components" deviceset="FUSE" device=""/>
<part name="U$5" library="sense_pcb_components" deviceset="FUSE" device=""/>
<part name="J1" library="sense_pcb_components" deviceset="DF11-18DP-2DSA(24)" device=""/>
<part name="U$6" library="sense_pcb_components" deviceset="BB_CONTACT" device=""/>
<part name="U$7" library="sense_pcb_components" deviceset="BB_CONTACT" device=""/>
<part name="U$8" library="sense_pcb_components" deviceset="BB_CONTACT" device=""/>
<part name="U$9" library="sense_pcb_components" deviceset="BB_CONTACT" device=""/>
<part name="U$10" library="sense_pcb_components" deviceset="BB_CONTACT" device=""/>
<part name="U$12" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$13" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$14" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$15" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$16" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$17" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$18" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$19" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$20" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$21" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$22" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$23" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$24" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$25" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$26" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$27" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$28" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$29" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$30" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$31" library="sense_pcb_components" deviceset="THERM_PIN" device=""/>
<part name="U$11" library="sense_pcb_components" deviceset="BB_CONTACT" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="5.08" y="7.62" smashed="yes" rot="R90"/>
<instance part="U$2" gate="G$1" x="12.7" y="7.62" smashed="yes" rot="R90"/>
<instance part="U$3" gate="G$1" x="20.32" y="7.62" smashed="yes" rot="R90"/>
<instance part="U$4" gate="G$1" x="27.94" y="7.62" smashed="yes" rot="R90"/>
<instance part="U$5" gate="G$1" x="35.56" y="7.62" smashed="yes" rot="R90"/>
<instance part="J1" gate="A" x="35.56" y="83.82" smashed="yes" rot="MR90">
<attribute name="NAME" x="40.8686" y="87.9856" size="2.0828" layer="95" ratio="6" rot="SMR90"/>
</instance>
<instance part="U$6" gate="G$1" x="5.08" y="10.16" smashed="yes" rot="R270"/>
<instance part="U$7" gate="G$1" x="12.7" y="10.16" smashed="yes" rot="R270"/>
<instance part="U$8" gate="G$1" x="20.32" y="10.16" smashed="yes" rot="R270"/>
<instance part="U$9" gate="G$1" x="27.94" y="10.16" smashed="yes" rot="R270"/>
<instance part="U$10" gate="G$1" x="35.56" y="10.16" smashed="yes" rot="R270"/>
<instance part="U$12" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$13" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$14" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$15" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$16" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$17" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$18" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$19" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$20" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$21" gate="G$1" x="22.86" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$22" gate="G$1" x="25.4" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$23" gate="G$1" x="25.4" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$24" gate="G$1" x="27.94" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$25" gate="G$1" x="27.94" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$26" gate="G$1" x="30.48" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$27" gate="G$1" x="30.48" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$28" gate="G$1" x="33.02" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$29" gate="G$1" x="33.02" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$30" gate="G$1" x="35.56" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$31" gate="G$1" x="35.56" y="83.82" smashed="yes" rot="R270"/>
<instance part="U$11" gate="G$1" x="-5.08" y="17.78" smashed="yes" rot="R270"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="P$2"/>
<pinref part="U$6" gate="G$1" pin="P$1"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="P$2"/>
<pinref part="U$7" gate="G$1" pin="P$1"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="P$2"/>
<pinref part="U$8" gate="G$1" pin="P$1"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="P$2"/>
<pinref part="U$9" gate="G$1" pin="P$1"/>
</segment>
</net>
<net name="THERM1" class="0">
<segment>
<pinref part="U$22" gate="G$1" pin="P$1"/>
<pinref part="U$23" gate="G$1" pin="P$1"/>
<pinref part="J1" gate="A" pin="5"/>
<junction x="25.4" y="83.82"/>
</segment>
</net>
<net name="THERM2" class="0">
<segment>
<pinref part="U$24" gate="G$1" pin="P$1"/>
<pinref part="U$25" gate="G$1" pin="P$1"/>
<pinref part="J1" gate="A" pin="4"/>
<junction x="27.94" y="83.82"/>
</segment>
</net>
<net name="THERM3" class="0">
<segment>
<pinref part="U$26" gate="G$1" pin="P$1"/>
<pinref part="U$27" gate="G$1" pin="P$1"/>
<pinref part="J1" gate="A" pin="3"/>
<junction x="30.48" y="83.82"/>
</segment>
</net>
<net name="THERM4" class="0">
<segment>
<pinref part="U$28" gate="G$1" pin="P$1"/>
<pinref part="U$29" gate="G$1" pin="P$1"/>
<pinref part="J1" gate="A" pin="2"/>
<junction x="33.02" y="83.82"/>
</segment>
</net>
<net name="THERM5" class="0">
<segment>
<pinref part="U$30" gate="G$1" pin="P$1"/>
<pinref part="U$31" gate="G$1" pin="P$1"/>
<pinref part="J1" gate="A" pin="1"/>
<junction x="35.56" y="83.82"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<wire x1="-5.08" y1="17.78" x2="-5.08" y2="43.18" width="0.1524" layer="91"/>
<wire x1="-5.08" y1="43.18" x2="17.78" y2="43.18" width="0.1524" layer="91"/>
<wire x1="17.78" y1="43.18" x2="17.78" y2="78.74" width="0.1524" layer="91"/>
<wire x1="17.78" y1="78.74" x2="20.32" y2="78.74" width="0.1524" layer="91"/>
<pinref part="J1" gate="A" pin="8"/>
<wire x1="17.78" y1="78.74" x2="17.78" y2="83.82" width="0.1524" layer="91"/>
<junction x="17.78" y="78.74"/>
<pinref part="J1" gate="A" pin="7"/>
<wire x1="20.32" y1="78.74" x2="20.32" y2="83.82" width="0.1524" layer="91"/>
<pinref part="U$11" gate="G$1" pin="P$1"/>
</segment>
</net>
<net name="THERMGND" class="0">
<segment>
<pinref part="U$12" gate="G$1" pin="P$1"/>
<pinref part="U$13" gate="G$1" pin="P$1"/>
<pinref part="U$14" gate="G$1" pin="P$1"/>
<pinref part="U$15" gate="G$1" pin="P$1"/>
<pinref part="U$16" gate="G$1" pin="P$1"/>
<pinref part="U$17" gate="G$1" pin="P$1"/>
<pinref part="U$18" gate="G$1" pin="P$1"/>
<pinref part="U$19" gate="G$1" pin="P$1"/>
<pinref part="U$20" gate="G$1" pin="P$1"/>
<pinref part="U$21" gate="G$1" pin="P$1"/>
<junction x="22.86" y="83.82"/>
<pinref part="J1" gate="A" pin="6"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<wire x1="-7.62" y1="78.74" x2="-5.08" y2="78.74" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="P$1"/>
<wire x1="35.56" y1="17.78" x2="35.56" y2="27.94" width="0.1524" layer="91"/>
<wire x1="35.56" y1="27.94" x2="-7.62" y2="27.94" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="27.94" x2="-7.62" y2="78.74" width="0.1524" layer="91"/>
<pinref part="J1" gate="A" pin="18"/>
<wire x1="-7.62" y1="78.74" x2="-7.62" y2="83.82" width="0.1524" layer="91"/>
<junction x="-7.62" y="78.74"/>
<pinref part="J1" gate="A" pin="17"/>
<wire x1="-5.08" y1="78.74" x2="-5.08" y2="83.82" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="P$2"/>
<pinref part="U$10" gate="G$1" pin="P$1"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="J1" gate="A" pin="16"/>
<pinref part="J1" gate="A" pin="15"/>
<wire x1="0" y1="78.74" x2="0" y2="83.82" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="78.74" x2="0" y2="78.74" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="78.74" x2="-2.54" y2="83.82" width="0.1524" layer="91"/>
<junction x="-2.54" y="78.74"/>
<pinref part="U$4" gate="G$1" pin="P$1"/>
<wire x1="27.94" y1="17.78" x2="27.94" y2="33.02" width="0.1524" layer="91"/>
<wire x1="27.94" y1="33.02" x2="-2.54" y2="33.02" width="0.1524" layer="91"/>
<wire x1="-2.54" y1="33.02" x2="-2.54" y2="78.74" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="J1" gate="A" pin="14"/>
<pinref part="J1" gate="A" pin="13"/>
<wire x1="5.08" y1="78.74" x2="5.08" y2="83.82" width="0.1524" layer="91"/>
<wire x1="2.54" y1="78.74" x2="5.08" y2="78.74" width="0.1524" layer="91"/>
<wire x1="2.54" y1="78.74" x2="2.54" y2="83.82" width="0.1524" layer="91"/>
<junction x="2.54" y="78.74"/>
<wire x1="2.54" y1="38.1" x2="2.54" y2="78.74" width="0.1524" layer="91"/>
<wire x1="20.32" y1="38.1" x2="2.54" y2="38.1" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="P$1"/>
<wire x1="20.32" y1="17.78" x2="20.32" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="J1" gate="A" pin="12"/>
<pinref part="J1" gate="A" pin="11"/>
<wire x1="10.16" y1="78.74" x2="10.16" y2="83.82" width="0.1524" layer="91"/>
<wire x1="7.62" y1="78.74" x2="10.16" y2="78.74" width="0.1524" layer="91"/>
<wire x1="7.62" y1="78.74" x2="7.62" y2="83.82" width="0.1524" layer="91"/>
<junction x="7.62" y="78.74"/>
<wire x1="7.62" y1="45.72" x2="7.62" y2="78.74" width="0.1524" layer="91"/>
<wire x1="12.7" y1="45.72" x2="7.62" y2="45.72" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="P$1"/>
<wire x1="12.7" y1="17.78" x2="12.7" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="J1" gate="A" pin="10"/>
<pinref part="J1" gate="A" pin="9"/>
<wire x1="15.24" y1="78.74" x2="15.24" y2="83.82" width="0.1524" layer="91"/>
<wire x1="12.7" y1="78.74" x2="15.24" y2="78.74" width="0.1524" layer="91"/>
<wire x1="12.7" y1="78.74" x2="12.7" y2="83.82" width="0.1524" layer="91"/>
<junction x="12.7" y="78.74"/>
<wire x1="12.7" y1="50.8" x2="12.7" y2="78.74" width="0.1524" layer="91"/>
<wire x1="5.08" y1="50.8" x2="12.7" y2="50.8" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="P$1"/>
<wire x1="5.08" y1="17.78" x2="5.08" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
