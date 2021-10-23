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
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
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
<library name="PBQ79656PAPTQ1">
<description>&lt;BQ7965x-Q1 Family of 12S, 14S, 16S Precision Automotive Battery Monitor, Balancer and Integrated Hardware Protector with up to SafeTITM-26262 ASIL-D Compliance&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys, modified by Joshua Feist&lt;/author&gt;</description>
<packages>
<package name="QFP50P1200X1200X120-65N">
<description>&lt;b&gt;PAP (S-PQFP-G64)_5&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-5.738" y="3.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="2" x="-5.738" y="3.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="3" x="-5.738" y="2.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="4" x="-5.738" y="2.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="5" x="-5.738" y="1.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="6" x="-5.738" y="1.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="7" x="-5.738" y="0.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="8" x="-5.738" y="0.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="9" x="-5.738" y="-0.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="10" x="-5.738" y="-0.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="11" x="-5.738" y="-1.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="12" x="-5.738" y="-1.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="13" x="-5.738" y="-2.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="14" x="-5.738" y="-2.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="15" x="-5.738" y="-3.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="16" x="-5.738" y="-3.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="17" x="-3.75" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="18" x="-3.25" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="19" x="-2.75" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="20" x="-2.25" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="21" x="-1.75" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="22" x="-1.25" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="23" x="-0.75" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="24" x="-0.25" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="25" x="0.25" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="26" x="0.75" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="27" x="1.25" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="28" x="1.75" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="29" x="2.25" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="30" x="2.75" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="31" x="3.25" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="32" x="3.75" y="-5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="33" x="5.738" y="-3.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="34" x="5.738" y="-3.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="35" x="5.738" y="-2.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="36" x="5.738" y="-2.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="37" x="5.738" y="-1.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="38" x="5.738" y="-1.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="39" x="5.738" y="-0.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="40" x="5.738" y="-0.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="41" x="5.738" y="0.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="42" x="5.738" y="0.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="43" x="5.738" y="1.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="44" x="5.738" y="1.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="45" x="5.738" y="2.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="46" x="5.738" y="2.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="47" x="5.738" y="3.25" dx="1.475" dy="0.3" layer="1"/>
<smd name="48" x="5.738" y="3.75" dx="1.475" dy="0.3" layer="1"/>
<smd name="49" x="3.75" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="50" x="3.25" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="51" x="2.75" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="52" x="2.25" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="53" x="1.75" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="54" x="1.25" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="55" x="0.75" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="56" x="0.25" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="57" x="-0.25" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="58" x="-0.75" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="59" x="-1.25" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="60" x="-1.75" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="61" x="-2.25" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="62" x="-2.75" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="63" x="-3.25" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="64" x="-3.75" y="5.738" dx="1.475" dy="0.3" layer="1" rot="R90"/>
<smd name="65" x="0" y="0" dx="8" dy="8" layer="1" rot="R90"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-6.725" y1="6.725" x2="6.725" y2="6.725" width="0.05" layer="51"/>
<wire x1="6.725" y1="6.725" x2="6.725" y2="-6.725" width="0.05" layer="51"/>
<wire x1="6.725" y1="-6.725" x2="-6.725" y2="-6.725" width="0.05" layer="51"/>
<wire x1="-6.725" y1="-6.725" x2="-6.725" y2="6.725" width="0.05" layer="51"/>
<wire x1="-5" y1="5" x2="5" y2="5" width="0.1" layer="51"/>
<wire x1="5" y1="5" x2="5" y2="-5" width="0.1" layer="51"/>
<wire x1="5" y1="-5" x2="-5" y2="-5" width="0.1" layer="51"/>
<wire x1="-5" y1="-5" x2="-5" y2="5" width="0.1" layer="51"/>
<wire x1="-5" y1="4.5" x2="-4.5" y2="5" width="0.1" layer="51"/>
<circle x="-6.225" y="4.5" radius="0.125" width="0.25" layer="25"/>
</package>
</packages>
<symbols>
<symbol name="PBQ79656PAPTQ1">
<wire x1="5.08" y1="7.62" x2="50.8" y2="7.62" width="0.254" layer="94"/>
<wire x1="50.8" y1="-45.72" x2="50.8" y2="7.62" width="0.254" layer="94"/>
<wire x1="50.8" y1="-45.72" x2="5.08" y2="-45.72" width="0.254" layer="94"/>
<wire x1="5.08" y1="7.62" x2="5.08" y2="-45.72" width="0.254" layer="94"/>
<text x="52.07" y="12.7" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="52.07" y="10.16" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="BAT" x="0" y="0" length="middle"/>
<pin name="CB16" x="0" y="-2.54" length="middle"/>
<pin name="VC16" x="0" y="-5.08" length="middle"/>
<pin name="CB15" x="0" y="-7.62" length="middle"/>
<pin name="VC15" x="0" y="-10.16" length="middle"/>
<pin name="CB14" x="0" y="-12.7" length="middle"/>
<pin name="VC14" x="0" y="-15.24" length="middle"/>
<pin name="CB13" x="0" y="-17.78" length="middle"/>
<pin name="VC13" x="0" y="-20.32" length="middle"/>
<pin name="CB12" x="0" y="-22.86" length="middle"/>
<pin name="VC12" x="0" y="-25.4" length="middle"/>
<pin name="CB11" x="0" y="-27.94" length="middle"/>
<pin name="VC11" x="0" y="-30.48" length="middle"/>
<pin name="CB10" x="0" y="-33.02" length="middle"/>
<pin name="VC10" x="0" y="-35.56" length="middle"/>
<pin name="CB9" x="0" y="-38.1" length="middle"/>
<pin name="VC9" x="7.62" y="-50.8" length="middle" rot="R90"/>
<pin name="CB8" x="10.16" y="-50.8" length="middle" rot="R90"/>
<pin name="VC8" x="12.7" y="-50.8" length="middle" rot="R90"/>
<pin name="CB7" x="15.24" y="-50.8" length="middle" rot="R90"/>
<pin name="VC7" x="17.78" y="-50.8" length="middle" rot="R90"/>
<pin name="CB6" x="20.32" y="-50.8" length="middle" rot="R90"/>
<pin name="VC6" x="22.86" y="-50.8" length="middle" rot="R90"/>
<pin name="CB5" x="25.4" y="-50.8" length="middle" rot="R90"/>
<pin name="VC5" x="27.94" y="-50.8" length="middle" rot="R90"/>
<pin name="CB4" x="30.48" y="-50.8" length="middle" rot="R90"/>
<pin name="VC4" x="33.02" y="-50.8" length="middle" rot="R90"/>
<pin name="CB3" x="35.56" y="-50.8" length="middle" rot="R90"/>
<pin name="VC3" x="38.1" y="-50.8" length="middle" rot="R90"/>
<pin name="CB2" x="40.64" y="-50.8" length="middle" rot="R90"/>
<pin name="VC2" x="43.18" y="-50.8" length="middle" rot="R90"/>
<pin name="CB1" x="45.72" y="-50.8" length="middle" rot="R90"/>
<pin name="NPNB" x="55.88" y="0" length="middle" rot="R180"/>
<pin name="LDOIN" x="55.88" y="-2.54" length="middle" rot="R180"/>
<pin name="CVSS" x="55.88" y="-5.08" length="middle" rot="R180"/>
<pin name="CVDD" x="55.88" y="-7.62" length="middle" rot="R180"/>
<pin name="NEG5V" x="55.88" y="-10.16" length="middle" rot="R180"/>
<pin name="COMHP" x="55.88" y="-12.7" length="middle" rot="R180"/>
<pin name="COMHN" x="55.88" y="-15.24" length="middle" rot="R180"/>
<pin name="COMLN" x="55.88" y="-17.78" length="middle" rot="R180"/>
<pin name="COMLP" x="55.88" y="-20.32" length="middle" rot="R180"/>
<pin name="AVSS" x="55.88" y="-22.86" length="middle" rot="R180"/>
<pin name="AVDD" x="55.88" y="-25.4" length="middle" rot="R180"/>
<pin name="REFHP" x="55.88" y="-27.94" length="middle" rot="R180"/>
<pin name="REFHM" x="55.88" y="-30.48" length="middle" rot="R180"/>
<pin name="VC0" x="55.88" y="-33.02" length="middle" rot="R180"/>
<pin name="CB0" x="55.88" y="-35.56" length="middle" rot="R180"/>
<pin name="VC1" x="55.88" y="-38.1" length="middle" rot="R180"/>
<pin name="AVSS?" x="7.62" y="12.7" length="middle" rot="R270"/>
<pin name="BBP(SRP)" x="10.16" y="12.7" length="middle" rot="R270"/>
<pin name="BBN(SRN)" x="12.7" y="12.7" length="middle" rot="R270"/>
<pin name="NFAULT" x="15.24" y="12.7" length="middle" rot="R270"/>
<pin name="GPIO1" x="17.78" y="12.7" length="middle" rot="R270"/>
<pin name="GPIO2" x="20.32" y="12.7" length="middle" rot="R270"/>
<pin name="GPIO3" x="22.86" y="12.7" length="middle" rot="R270"/>
<pin name="GPIO4" x="25.4" y="12.7" length="middle" rot="R270"/>
<pin name="GPIO5" x="27.94" y="12.7" length="middle" rot="R270"/>
<pin name="GPIO6" x="30.48" y="12.7" length="middle" rot="R270"/>
<pin name="GPIO7" x="33.02" y="12.7" length="middle" rot="R270"/>
<pin name="GPIO8" x="35.56" y="12.7" length="middle" rot="R270"/>
<pin name="TX" x="38.1" y="12.7" length="middle" rot="R270"/>
<pin name="RX" x="40.64" y="12.7" length="middle" rot="R270"/>
<pin name="TSREF" x="43.18" y="12.7" length="middle" rot="R270"/>
<pin name="DVSS" x="45.72" y="12.7" length="middle" rot="R270"/>
<pin name="DVDD" x="48.26" y="12.7" length="middle" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PBQ79656PAPTQ1" prefix="IC">
<description>&lt;b&gt;BQ7965x-Q1 Family of 12S, 14S, 16S Precision Automotive Battery Monitor, Balancer and Integrated Hardware Protector with up to SafeTITM-26262 ASIL-D Compliance&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.ti.com/lit/ds/symlink/bq79616-q1.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="PBQ79656PAPTQ1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="QFP50P1200X1200X120-65N">
<connects>
<connect gate="G$1" pin="AVDD" pad="38"/>
<connect gate="G$1" pin="AVSS" pad="39"/>
<connect gate="G$1" pin="AVSS?" pad="65"/>
<connect gate="G$1" pin="BAT" pad="1"/>
<connect gate="G$1" pin="BBN(SRN)" pad="63"/>
<connect gate="G$1" pin="BBP(SRP)" pad="64"/>
<connect gate="G$1" pin="CB0" pad="34"/>
<connect gate="G$1" pin="CB1" pad="32"/>
<connect gate="G$1" pin="CB10" pad="14"/>
<connect gate="G$1" pin="CB11" pad="12"/>
<connect gate="G$1" pin="CB12" pad="10"/>
<connect gate="G$1" pin="CB13" pad="8"/>
<connect gate="G$1" pin="CB14" pad="6"/>
<connect gate="G$1" pin="CB15" pad="4"/>
<connect gate="G$1" pin="CB16" pad="2"/>
<connect gate="G$1" pin="CB2" pad="30"/>
<connect gate="G$1" pin="CB3" pad="28"/>
<connect gate="G$1" pin="CB4" pad="26"/>
<connect gate="G$1" pin="CB5" pad="24"/>
<connect gate="G$1" pin="CB6" pad="22"/>
<connect gate="G$1" pin="CB7" pad="20"/>
<connect gate="G$1" pin="CB8" pad="18"/>
<connect gate="G$1" pin="CB9" pad="16"/>
<connect gate="G$1" pin="COMHN" pad="42"/>
<connect gate="G$1" pin="COMHP" pad="43"/>
<connect gate="G$1" pin="COMLN" pad="41"/>
<connect gate="G$1" pin="COMLP" pad="40"/>
<connect gate="G$1" pin="CVDD" pad="45"/>
<connect gate="G$1" pin="CVSS" pad="46"/>
<connect gate="G$1" pin="DVDD" pad="49"/>
<connect gate="G$1" pin="DVSS" pad="50"/>
<connect gate="G$1" pin="GPIO1" pad="61"/>
<connect gate="G$1" pin="GPIO2" pad="60"/>
<connect gate="G$1" pin="GPIO3" pad="59"/>
<connect gate="G$1" pin="GPIO4" pad="58"/>
<connect gate="G$1" pin="GPIO5" pad="57"/>
<connect gate="G$1" pin="GPIO6" pad="56"/>
<connect gate="G$1" pin="GPIO7" pad="55"/>
<connect gate="G$1" pin="GPIO8" pad="54"/>
<connect gate="G$1" pin="LDOIN" pad="47"/>
<connect gate="G$1" pin="NEG5V" pad="44"/>
<connect gate="G$1" pin="NFAULT" pad="62"/>
<connect gate="G$1" pin="NPNB" pad="48"/>
<connect gate="G$1" pin="REFHM" pad="36"/>
<connect gate="G$1" pin="REFHP" pad="37"/>
<connect gate="G$1" pin="RX" pad="52"/>
<connect gate="G$1" pin="TSREF" pad="51"/>
<connect gate="G$1" pin="TX" pad="53"/>
<connect gate="G$1" pin="VC0" pad="35"/>
<connect gate="G$1" pin="VC1" pad="33"/>
<connect gate="G$1" pin="VC10" pad="15"/>
<connect gate="G$1" pin="VC11" pad="13"/>
<connect gate="G$1" pin="VC12" pad="11"/>
<connect gate="G$1" pin="VC13" pad="9"/>
<connect gate="G$1" pin="VC14" pad="7"/>
<connect gate="G$1" pin="VC15" pad="5"/>
<connect gate="G$1" pin="VC16" pad="3"/>
<connect gate="G$1" pin="VC2" pad="31"/>
<connect gate="G$1" pin="VC3" pad="29"/>
<connect gate="G$1" pin="VC4" pad="27"/>
<connect gate="G$1" pin="VC5" pad="25"/>
<connect gate="G$1" pin="VC6" pad="23"/>
<connect gate="G$1" pin="VC7" pad="21"/>
<connect gate="G$1" pin="VC8" pad="19"/>
<connect gate="G$1" pin="VC9" pad="17"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="BQ7965x-Q1 Family of 12S, 14S, 16S Precision Automotive Battery Monitor, Balancer and Integrated Hardware Protector with up to SafeTITM-26262 ASIL-D Compliance" constant="no"/>
<attribute name="HEIGHT" value="1.2mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Texas Instruments" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="PBQ79656PAPTQ1" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="" constant="no"/>
</technology>
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
<part name="IC1" library="PBQ79656PAPTQ1" deviceset="PBQ79656PAPTQ1" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="IC1" gate="G$1" x="55.88" y="73.66" smashed="yes">
<attribute name="NAME" x="107.95" y="86.36" size="1.778" layer="95" align="center-left"/>
<attribute name="VALUE" x="107.95" y="83.82" size="1.778" layer="96" align="center-left"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="BAT"/>
<wire x1="55.88" y1="73.66" x2="7.62" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB16"/>
<wire x1="55.88" y1="71.12" x2="7.62" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC16"/>
<wire x1="55.88" y1="68.58" x2="7.62" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB15"/>
<wire x1="55.88" y1="66.04" x2="7.62" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC15"/>
<wire x1="55.88" y1="63.5" x2="7.62" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB14"/>
<wire x1="55.88" y1="60.96" x2="7.62" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC14"/>
<wire x1="55.88" y1="58.42" x2="7.62" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB13"/>
<wire x1="55.88" y1="55.88" x2="7.62" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC13"/>
<wire x1="55.88" y1="53.34" x2="7.62" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB12"/>
<wire x1="55.88" y1="50.8" x2="7.62" y2="50.8" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC12"/>
<wire x1="55.88" y1="48.26" x2="7.62" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB11"/>
<wire x1="55.88" y1="45.72" x2="7.62" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC11"/>
<wire x1="55.88" y1="43.18" x2="7.62" y2="43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB10"/>
<wire x1="55.88" y1="40.64" x2="7.62" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC10"/>
<wire x1="55.88" y1="38.1" x2="7.62" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB9"/>
<wire x1="55.88" y1="35.56" x2="7.62" y2="35.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC9"/>
<wire x1="63.5" y1="22.86" x2="55.88" y2="22.86" width="0.1524" layer="91"/>
<wire x1="55.88" y1="22.86" x2="55.88" y2="33.02" width="0.1524" layer="91"/>
<wire x1="55.88" y1="33.02" x2="7.62" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB8"/>
<wire x1="66.04" y1="22.86" x2="66.04" y2="20.32" width="0.1524" layer="91"/>
<wire x1="66.04" y1="20.32" x2="53.34" y2="20.32" width="0.1524" layer="91"/>
<wire x1="53.34" y1="20.32" x2="53.34" y2="30.48" width="0.1524" layer="91"/>
<wire x1="53.34" y1="30.48" x2="7.62" y2="30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC8"/>
<wire x1="68.58" y1="22.86" x2="68.58" y2="17.78" width="0.1524" layer="91"/>
<wire x1="68.58" y1="17.78" x2="50.8" y2="17.78" width="0.1524" layer="91"/>
<wire x1="50.8" y1="17.78" x2="50.8" y2="27.94" width="0.1524" layer="91"/>
<wire x1="50.8" y1="27.94" x2="7.62" y2="27.94" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB7"/>
<wire x1="71.12" y1="22.86" x2="71.12" y2="15.24" width="0.1524" layer="91"/>
<wire x1="71.12" y1="15.24" x2="48.26" y2="15.24" width="0.1524" layer="91"/>
<wire x1="48.26" y1="15.24" x2="48.26" y2="25.4" width="0.1524" layer="91"/>
<wire x1="48.26" y1="25.4" x2="7.62" y2="25.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC7"/>
<wire x1="73.66" y1="22.86" x2="73.66" y2="12.7" width="0.1524" layer="91"/>
<wire x1="73.66" y1="12.7" x2="45.72" y2="12.7" width="0.1524" layer="91"/>
<wire x1="45.72" y1="12.7" x2="45.72" y2="22.86" width="0.1524" layer="91"/>
<wire x1="45.72" y1="22.86" x2="7.62" y2="22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB6"/>
<wire x1="76.2" y1="22.86" x2="76.2" y2="10.16" width="0.1524" layer="91"/>
<wire x1="76.2" y1="10.16" x2="43.18" y2="10.16" width="0.1524" layer="91"/>
<wire x1="43.18" y1="10.16" x2="43.18" y2="20.32" width="0.1524" layer="91"/>
<wire x1="43.18" y1="20.32" x2="7.62" y2="20.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC6"/>
<wire x1="78.74" y1="22.86" x2="78.74" y2="7.62" width="0.1524" layer="91"/>
<wire x1="78.74" y1="7.62" x2="40.64" y2="7.62" width="0.1524" layer="91"/>
<wire x1="40.64" y1="7.62" x2="40.64" y2="17.78" width="0.1524" layer="91"/>
<wire x1="40.64" y1="17.78" x2="7.62" y2="17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB5"/>
<wire x1="81.28" y1="22.86" x2="81.28" y2="5.08" width="0.1524" layer="91"/>
<wire x1="81.28" y1="5.08" x2="38.1" y2="5.08" width="0.1524" layer="91"/>
<wire x1="38.1" y1="5.08" x2="38.1" y2="15.24" width="0.1524" layer="91"/>
<wire x1="38.1" y1="15.24" x2="7.62" y2="15.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC5"/>
<wire x1="83.82" y1="22.86" x2="83.82" y2="2.54" width="0.1524" layer="91"/>
<wire x1="83.82" y1="2.54" x2="35.56" y2="2.54" width="0.1524" layer="91"/>
<wire x1="35.56" y1="2.54" x2="35.56" y2="12.7" width="0.1524" layer="91"/>
<wire x1="35.56" y1="12.7" x2="7.62" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB4"/>
<wire x1="86.36" y1="22.86" x2="86.36" y2="0" width="0.1524" layer="91"/>
<wire x1="86.36" y1="0" x2="33.02" y2="0" width="0.1524" layer="91"/>
<wire x1="33.02" y1="0" x2="33.02" y2="10.16" width="0.1524" layer="91"/>
<wire x1="33.02" y1="10.16" x2="7.62" y2="10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$27" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC4"/>
<wire x1="88.9" y1="22.86" x2="88.9" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="88.9" y1="-2.54" x2="30.48" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="30.48" y1="-2.54" x2="30.48" y2="7.62" width="0.1524" layer="91"/>
<wire x1="30.48" y1="7.62" x2="7.62" y2="7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$28" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB3"/>
<wire x1="91.44" y1="22.86" x2="91.44" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="91.44" y1="-5.08" x2="27.94" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="27.94" y1="-5.08" x2="27.94" y2="5.08" width="0.1524" layer="91"/>
<wire x1="27.94" y1="5.08" x2="7.62" y2="5.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$29" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC3"/>
<wire x1="93.98" y1="22.86" x2="93.98" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="93.98" y1="-7.62" x2="25.4" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="25.4" y1="-7.62" x2="25.4" y2="2.54" width="0.1524" layer="91"/>
<wire x1="25.4" y1="2.54" x2="7.62" y2="2.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$30" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB2"/>
<wire x1="96.52" y1="22.86" x2="96.52" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="96.52" y1="-10.16" x2="22.86" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="22.86" y1="-10.16" x2="22.86" y2="0" width="0.1524" layer="91"/>
<wire x1="22.86" y1="0" x2="7.62" y2="0" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$31" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC2"/>
<wire x1="99.06" y1="22.86" x2="99.06" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="99.06" y1="-12.7" x2="20.32" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-12.7" x2="20.32" y2="-2.54" width="0.1524" layer="91"/>
<wire x1="20.32" y1="-2.54" x2="7.62" y2="-2.54" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$32" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB1"/>
<wire x1="101.6" y1="22.86" x2="101.6" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="101.6" y1="-15.24" x2="17.78" y2="-15.24" width="0.1524" layer="91"/>
<wire x1="17.78" y1="-15.24" x2="17.78" y2="-5.08" width="0.1524" layer="91"/>
<wire x1="17.78" y1="-5.08" x2="7.62" y2="-5.08" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$33" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC1"/>
<wire x1="111.76" y1="35.56" x2="111.76" y2="25.4" width="0.1524" layer="91"/>
<wire x1="111.76" y1="25.4" x2="104.14" y2="25.4" width="0.1524" layer="91"/>
<wire x1="104.14" y1="25.4" x2="104.14" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="104.14" y1="-17.78" x2="15.24" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="15.24" y1="-17.78" x2="15.24" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="15.24" y1="-7.62" x2="7.62" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$34" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="CB0"/>
<wire x1="111.76" y1="38.1" x2="114.3" y2="38.1" width="0.1524" layer="91"/>
<wire x1="114.3" y1="38.1" x2="114.3" y2="22.86" width="0.1524" layer="91"/>
<wire x1="114.3" y1="22.86" x2="106.68" y2="22.86" width="0.1524" layer="91"/>
<wire x1="106.68" y1="22.86" x2="106.68" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="106.68" y1="-20.32" x2="12.7" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="12.7" y1="-20.32" x2="12.7" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="12.7" y1="-10.16" x2="7.62" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$35" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VC0"/>
<wire x1="111.76" y1="40.64" x2="116.84" y2="40.64" width="0.1524" layer="91"/>
<wire x1="116.84" y1="40.64" x2="116.84" y2="20.32" width="0.1524" layer="91"/>
<wire x1="116.84" y1="20.32" x2="109.22" y2="20.32" width="0.1524" layer="91"/>
<wire x1="109.22" y1="20.32" x2="109.22" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="109.22" y1="-22.86" x2="10.16" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-22.86" x2="10.16" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="10.16" y1="-12.7" x2="7.62" y2="-12.7" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
