#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*Alkio, josta loytyy niin avain, vasemmalla etta oikealla olevat alkiot*/
struct luku {
    int avain;
    struct luku *vasen;
    struct luku *oikea;
};

/*Funktio uuden alkion luomiseksi. Huom. tata kutsutaan vain kerran, joten ei ole valttamattomyys omana funktionaan*/
struct luku* uusiLuku(int numero) {
    /*Alustetaan alkio, varataan muisti ja palautetaan luotu alkio*/
    struct luku* luku = (struct luku*)malloc(sizeof(struct luku));
    luku->avain = numero;
    luku->vasen = NULL;
    luku->oikea = NULL;
    return luku;
}

/*Lasketaan alkion korkeus*/
int etsiKorkeus(struct luku* alkio) {
    int korkeus=0;
    if (alkio!=NULL) {
        int tmp = 0;
        /*Lasketaan seka vasemman etta oikean puolen korkeudet ja valitaan korkeampi ja palautetaan se*/
        int vasenKorkeus = etsiKorkeus(alkio->vasen);
        int oikeaKorkeus = etsiKorkeus(alkio->oikea);
        if (vasenKorkeus > oikeaKorkeus) 
            tmp = vasenKorkeus;
        else 
            tmp = oikeaKorkeus;
        /*Nostetaan korkeutta aina 1:lla kun loytyy uusi syvyys*/
        korkeus = 1 + tmp;
    }
    return korkeus;
}
/*RR-kierto. Siirretaan ensin alkuperaisen alkion oikealla puolella olevan alkion vasemmanpuoleiset
alkiot alkuperaisen alkion oikealle puolelle ja tehdaan alkuperaisesta alkiosta
sen alkuperaisen oikeanpuoleisen alkion vasemmanpuoleinen alkio.*/
struct luku* kiertoRR(struct luku* alkio) {
    struct luku* temp = alkio->oikea;
    alkio->oikea = temp->vasen;
    temp->vasen= alkio;
    return temp;
}
/*LL-kierto. Sama kuin RR-kierto, mutta peilikuvana.*/
struct luku* kiertoLL(struct luku* alkio) {
    struct luku* temp = alkio->vasen;
    alkio->vasen = temp->oikea;
    temp->oikea = alkio;
    return temp;
}
/*LR-kierto. Tehdaan ensin RR-kierto alkuperaisen alkion vasemmanpuoleiselle alkiolle ja sitten
LL-kierto alkuperaiselle alkiolle*/
struct luku* kiertoLR(struct luku* alkio) {
    struct luku* temp = alkio->vasen;
    alkio->vasen = kiertoRR(temp);
    return kiertoLL(alkio);
}
/*RL-kierto. Sama kuin LR-kierto, mutta peilikuvana.*/
struct luku* kiertoRL(struct luku* alkio) {
    struct luku* temp = alkio->oikea;
    alkio->oikea = kiertoLL(temp);
    return kiertoRR(alkio);
}

/*Tulostetaan puu. syvyys-muuttuja laskee syvyyden, jota kaytetaan apuna puumaisen rakenteen
tulostamisessa. Rakenne on lahes sama kuin kaannetty inorder-tulostus*/
void puuTulostus(struct luku *alkio, int syvyys) {
    if (alkio!=NULL) {
        puuTulostus(alkio->oikea, syvyys+1);
            for (int i=0;i<syvyys;i++) {
                printf("\t");
                
            }
            printf("%d\n",alkio->avain);
        
        
        puuTulostus(alkio->vasen, syvyys+1);
    }
}

/*Tasapainotus-funktio*/
struct luku* tasapainotus(struct luku* alkio) {
    /*Katsotaan, onko alkiossa epatasapainoa (onko syvyydessa eroa enemmän kuin 1),
    ja etta onko se vasemmalla puolella*/
    if (etsiKorkeus(alkio->vasen) - etsiKorkeus(alkio->oikea) >1) {
        /*Katsotaan onko epatasapaino vasen-alkion vasemmalla vai oikealla puolella.
        Tulostetaan tehtava kierto ja epatasapainosta olevan alkion muodostama puu ennen
        ja jalkeen kierron*/
        if (etsiKorkeus(alkio->vasen->vasen) - etsiKorkeus(alkio->vasen->oikea) >0) {
            printf("Havaittu epatasapaino! Tasapainotetaan LL-kierrolla.\nVANHA:\n");
            puuTulostus(alkio,0);
            alkio=kiertoLL(alkio);
            printf("UUSI:\n");
            puuTulostus(alkio,0);
        }
        else {
            printf("Havaittu epatasapaino! Tasapainotetaan LR-kierrolla.\nVANHA:\n");
            puuTulostus(alkio,0);
            alkio=kiertoLR(alkio);
            printf("UUSI:\n");
            puuTulostus(alkio,0);
        }
    }
    /*Katsotaan, onko epatasapaino oikealla puolella*/
    else if(etsiKorkeus(alkio->vasen) - etsiKorkeus(alkio->oikea) < -1) {
        /*Katsotaan onko epatasapaino oikea-alkion vasemmalla vai oikealla puolella.
        Tulostetaan tehtava kierto ja epatasapainosta olevan alkion muodostama puu ennen
        ja jalkeen kierron*/
        if(etsiKorkeus(alkio->oikea->vasen) - etsiKorkeus(alkio->oikea->oikea) >0) {
            printf("Havaittu epatasapaino! Tasapainotetaan RL-kierrolla.\nVANHA:\n");
            puuTulostus(alkio,0);
            alkio=kiertoRL(alkio);
            printf("UUSI:\n");
            puuTulostus(alkio,0);
        }
        else    {
            printf("Havaittu epatasapaino! Tasapainotetaan RR-kierrolla.\nVANHA:\n");
            puuTulostus(alkio,0);
            alkio=kiertoRR(alkio);
            printf("UUSI:\n");
            puuTulostus(alkio,0);
        }
    }
    return alkio;
}

/*Syotto-funktio. numero-muuttuja tarkoittaa lisattavaa avainta ja edellinen-alkio taas pitaa kirjaa
siita, minka alkion lapseksi tehdaan uusi alkio*/
struct luku* syotto(struct luku* alkio, int numero, struct luku* edellinen) {
    if (alkio==NULL) {
        if (edellinen!=NULL) {
            printf("Luku %d sijoitettiin luvun %d alle.\n", numero, edellinen->avain);
        }
        else {
            printf("Luotiin uusi puu, jonka ainoa alkio on %d.\n", numero);
        }
        alkio = uusiLuku(numero);
    }
    
    else if (numero == alkio->avain) return NULL;
    /*Rekursiivisesti etsitaan oikea kohta mihin halutaan sijoittaa haluttu avain.
    Siirrytaan vasemmalle.*/
    else if (numero < alkio->avain) {
        alkio->vasen = syotto(alkio->vasen, numero,alkio);
        /*Tasapainoitetaan uusi puu*/
        alkio = tasapainotus(alkio);
    }
    /*Siirrytaan oikealle*/
    else if (numero > alkio->avain) {
        alkio->oikea = syotto(alkio->oikea, numero,alkio);
        alkio = tasapainotus(alkio);
    }
    return alkio;
}

/*Etsimis-funktio, joka rekursiivisesti etsii haluttua avainta*/
int etsiLuku(struct luku* alkio, int numero) {
    /*Avainta ei loytynyt*/
    if (alkio==NULL) {
        return 0;
    }
    /*Avain loytyi*/
    else if (alkio->avain == numero) {
        return 1;
    }
    /*Siirrytaan vasemmalle*/
    else if (numero < alkio->avain) {
        return etsiLuku(alkio->vasen, numero);
    }
    /*Siirrytaan oikealle*/
    else if (numero > alkio->avain) {
        return etsiLuku(alkio->oikea, numero);
    }
    
}

/*Tiedoston lukemiseen kaytetty funktio*/
struct luku* tiedostonluku() {
    /*tmp-alkio on palautettava puu, temp-alkiota kaytetaan apuna kun syotetaan uutta avainta,
    jotta syotto-funktio tulostaisi oikein sen, minka alkion alle sijoitetaan avain.*/
    struct luku *tmp = NULL;
    struct luku *temp = NULL;
    /*Kysytaan tiedoston nimea ja avataan se*/
    
    /*
    Kaytin itse avl_luvut.txt-nimista tiedostoa
    */
    FILE* tiedosto;
    char muisti[256];
    char tiedostonNimi[30];
    printf("Luettavan tiedoston nimi: ");
    scanf("%s", tiedostonNimi);
    tiedosto = fopen(tiedostonNimi, "r");
    /*Jos tiedostoa ei ole, kysytaan uudestaan*/
    while (tiedosto==NULL) {
        printf("Tiedoston avaaminen ei onnistunut!\nSyota uudestaan: ");
        scanf("%s", tiedostonNimi);
        tiedosto = fopen(tiedostonNimi, "r");
    }
    /*Luetaan riveittain tiedostoa*/
    while (fgets(muisti, sizeof(muisti)-1, tiedosto) != NULL) {
        /*Huom! Kayttamassani testiaineistossa luvut on jokainen omalla rivillaan, joten poistetaan
        rivinvaihtomerkki ennen kuin muutetaan int-muuttujaksi*/
        muisti[strcspn(muisti, "\n")] = '\0';
        int number = atoi(muisti);
        /*Syotetaan puuhun loydetty avain*/
        tmp = syotto(tmp,number,temp);
    }
    return tmp;
}
int main(void) {
    struct luku *puu;
    /*tmp-alkiota kaytetaan apuna kun syotetaan uutta avainta*/
    struct luku *tmp = NULL;
    /*Luetaan puuhun tiedostosta*/
    puu = tiedostonluku();
    /*Tulostetaan luettu puu*/
    printf("\nTiedostosta luettu puu:\n");
    puuTulostus(puu,0);
    
    
    /*Tehdaan valintarakenne-loop.*/
    int valinta=1;
    int avain=0;
    char valitseminen[20];
    while(valinta!=4) {
        printf("\n1)Etsi avain\n2)Lisaa uusi avain\n3)Tulosta puu\n4)Lopeta\nValitse: ");
        scanf("%s",valitseminen);
        valinta = atoi(valitseminen);
        /*Etsi-valinta*/
        if (valinta==1) {
            printf("Etsi avain: ");
            scanf("%s",valitseminen);
            avain = atoi(valitseminen);
            if(etsiLuku(puu,avain)) 
                printf("Numero %d loytyi onnistuneesti!\n", avain);
            else
                printf("Numero %d ei loytynyt!\n",avain);
        }
        /*Lisays-valinta*/
        else if (valinta==2) {
            printf("Lisaa uusi avain: ");
            scanf("%s",valitseminen);
            avain = atoi(valitseminen);
            puu = syotto(puu,avain,tmp);
        }
        /*Tulostus-valinta*/
        else if (valinta==3) puuTulostus(puu,0);
        /*Ei tunnistettu, jatketaan looppia*/
        else if (valinta==4) break;
        else{
            printf("Valintaa ei tunnistettu.\n");
            valinta=1;
        }
    }
    /*Tulostetaan lopetusviesti*/
    printf("AVL-puun demoesitys on keskeytetty.\n");

}