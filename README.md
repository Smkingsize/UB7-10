# UB7-10
Here is my Answer on the queen problem handed inthe lecture
Im Laufe der n¨achsten Ubungen werden wir uns f ¨ ur das Damenproblem interessieren. In dem ¨
Problem geht es darum, auf einem n × n-Brett genau n Damen zu platzieren, ohne dass die eine
die andere angreifen kann. Zwei Damen durfen also niemals auf derselben Diagonale oder Linie ¨
sein. Das Problem besteht darin herauszufinden, wie viele L¨osungen es gibt. L¨osungen k¨onnen
Symmetrien aufweisen, aber das interessiert uns erst einmal nicht.
In den kommenden Ubungsbl ¨ ¨attern 7 (bis voraussichtlich 10) werden wir dieses Problem mit einer
besonderen Darstellung l¨osen: BDDs (binary decision diagrams). Das ist ein Graph (im Moment:
ein Baum) von Knoten. Jeder Knoten beschreibt eine Position einer Dame und stellt die Frage ¨Ist
die Dame an der n¨achsten Stelle da?”. Jeder Knoten hat dann zwei Nachfolger : “wenn sie da ist”
und “wenn sie nicht da ist”, daher auch der Name “If-Then-Else” fur jeden Knoten. Es gibt zwei ¨
besondere Bl¨atter: 0 (keine L¨osung zum Damenproblem) und 1 (L¨osung zum Damenproblem).
Fur den Nachfolger einer Position stellen wir eine Dame in der ersten leeren Spalte (von links ¨
nach rechts) und setzen sie dort ein oder setzen keine Dame an dieser Stelle.
