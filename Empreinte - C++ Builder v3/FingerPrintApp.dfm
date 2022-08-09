object TForm1: TTForm1
  Left = 0
  Top = 0
  Caption = 'FingerPrint Scanner '#55357#56393
  ClientHeight = 375
  ClientWidth = 688
  Color = clTeal
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 11
    Width = 57
    Height = 13
    Caption = 'Identifiant :'
  end
  object numéro: TLabel
    Left = 314
    Top = 267
    Width = 47
    Height = 13
    Caption = 'R'#233'sultat :'
  end
  object btnOuvrir: TButton
    Left = 383
    Top = 45
    Width = 105
    Height = 39
    Caption = 'OUVRIR'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = btnOuvrirClick
  end
  object textResultat: TEdit
    Left = 367
    Top = 264
    Width = 304
    Height = 65
    TabOrder = 1
  end
  object btnRegisterFigner: TButton
    Left = 27
    Top = 112
    Width = 158
    Height = 41
    Caption = 'ENREGISTRER EMPREINTE'
    TabOrder = 2
    OnClick = btnRegisterFignerClick
  end
  object Button4: TButton
    Left = 27
    Top = 170
    Width = 158
    Height = 39
    Caption = 'SUPRRIMER IDENTITFIANT'
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 360
    Top = 112
    Width = 290
    Height = 137
    Caption = 'Panel1'
    Locked = True
    ShowCaption = False
    TabOrder = 4
  end
  object btnFermer: TButton
    Left = 520
    Top = 45
    Width = 105
    Height = 39
    Caption = 'FERMER'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'System'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = btnFermerClick
  end
  object btnEnvoyer: TButton
    Left = 279
    Top = 170
    Width = 75
    Height = 25
    Caption = 'LED ON'
    TabOrder = 6
    OnClick = btnEnvoyerClick
  end
  object btnLedOff: TButton
    Left = 279
    Top = 139
    Width = 75
    Height = 25
    Caption = 'LED OFF'
    TabOrder = 7
    OnClick = btnLedOffClick
  end
  object btnGetImage: TButton
    Left = 27
    Top = 228
    Width = 158
    Height = 37
    Caption = 'ENREGISTRE IMAGE'
    TabOrder = 8
    OnClick = btnGetImageClick
  end
  object btnCancel: TButton
    Left = 279
    Top = 201
    Width = 75
    Height = 25
    Caption = 'ANNULER'
    TabOrder = 9
  end
  object btnID: TComboBox
    Left = 71
    Top = 8
    Width = 90
    Height = 21
    TabOrder = 10
    Items.Strings = (
      '1'#9
      '2'#9
      '3'#9
      '4'#9
      '5'#9
      '6'#9
      '7'#9
      '8'#9
      '9'#9
      '10'#9
      '11'#9
      '12'#9
      '13'#9
      '14'#9
      '15'#9
      '16'#9
      '17'#9
      '18'#9
      '19'#9
      '20'#9
      '21'#9
      '22'#9
      '23'#9
      '24'#9
      '25'#9
      '26'#9
      '27'#9
      '28'#9
      '29'#9
      '30'#9
      '31'#9
      '32'#9
      '33'#9
      '34'#9
      '35'#9
      '36'#9
      '37'#9
      '38'#9
      '39'#9
      '40'#9
      '41'#9
      '42'#9
      '43'#9
      '44'#9
      '45'#9
      '46'#9
      '47'#9
      '48'#9
      '49'#9
      '50'#9
      '51'#9
      '52'#9
      '53'#9
      '54'#9
      '55'#9
      '56'#9
      '57'#9
      '58'#9
      '59'#9
      '60'#9
      '61'#9
      '62'#9
      '63'#9
      '64'#9
      '65'#9
      '66'#9
      '67'#9
      '68'#9
      '69'#9
      '70'#9
      '71'#9
      '72'#9
      '73'#9
      '74'#9
      '75'#9
      '76'#9
      '77'#9
      '78'#9
      '79'#9
      '80'#9
      '81'#9
      '82'#9
      '83'#9
      '84'#9
      '85'#9
      '86'#9
      '87'#9
      '88'#9
      '89'#9
      '90'#9
      '91'#9
      '92'#9
      '93'#9
      '94'#9
      '95'#9
      '96'#9
      '97'#9
      '98'#9
      '99'#9
      '100'#9
      '101'#9
      '102'#9
      '103'#9
      '104'#9
      '105'#9
      '106'#9
      '107'#9
      '108'#9
      '109'#9
      '110'#9
      '111'#9
      '112'#9
      '113'#9
      '114'#9
      '115'#9
      '116'#9
      '117'#9
      '118'#9
      '119'#9
      '120'#9
      '121'#9
      '122'#9
      '123'#9
      '124'#9
      '125'#9
      '126'#9
      '127'#9
      '128'#9
      '129'#9
      '130'#9
      '131'#9
      '132'#9
      '133'#9
      '134'#9
      '135'#9
      '136'#9
      '137'#9
      '138'#9
      '139'#9
      '140'#9
      '141'#9
      '142'#9
      '143'#9
      '144'#9
      '145'#9
      '146'#9
      '147'#9
      '148'#9
      '149'#9
      '150'#9
      '151'#9
      '152'#9
      '153'#9
      '154'#9
      '155'#9
      '156'#9
      '157'#9
      '158'#9
      '159'#9
      '160'#9
      '161'#9
      '162'#9
      '163'#9
      '164'#9
      '165'#9
      '166'#9
      '167'#9
      '168'#9
      '169'#9
      '170'#9
      '171'#9
      '172'#9
      '173'#9
      '174'#9
      '175'#9
      '176'#9
      '177'#9
      '178'#9
      '179'#9
      '180'#9
      '181'#9
      '182'#9
      '183'#9
      '184'#9
      '185'#9
      '186'#9
      '187'#9
      '188'#9
      '189'#9
      '190'#9
      '191'#9
      '192'#9
      '193'#9
      '194'#9
      '195'#9
      '196'#9
      '197'#9
      '198'#9
      '199'#9)
  end
  object btnTest: TButton
    Left = 232
    Top = 52
    Width = 75
    Height = 25
    Caption = 'test'
    TabOrder = 11
    OnClick = btnTestClick
  end
  object Button1: TButton
    Left = 232
    Top = 83
    Width = 75
    Height = 25
    Caption = 'testTrame'
    TabOrder = 12
    OnClick = Button1Click
  end
end
