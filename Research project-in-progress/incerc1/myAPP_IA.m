classdef myAPP_IA < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure              matlab.ui.Figure
        ALGORITMGMenu         matlab.ui.container.Menu
        ALGORITMGPPMenu       matlab.ui.container.Menu
        ALGORITMGPCMenu       matlab.ui.container.Menu
        ALGORITMKaczmarzMenu  matlab.ui.container.Menu
        UITable               matlab.ui.control.Table
        UIAxes                matlab.ui.control.UIAxes
    end

    methods (Access = private)

        % Callback function
        function AmplitudeSliderValueChanged(app, event)

      
        end

        % Menu selected function: ALGORITMGMenu
        function ALGORITMGMenuSelected(app, event)
            run('S_REZ_G.m');
        end
        app.UITable = uitable(app.UIFigure);
        app.UITable.ColumnName = {'N [N]'; 'Pos. [mm]'; 'Q [N]'; 'Pos. [mm]'; 'M [Nm]'; 'Pos. [mm]'};
        app.UITable.RowName={};
        app.UITable.ColumnEditable = true;
        app.UITable.Position= [47 209 302 185];
    end

    % App initialization and construction
    methods (Access = public)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure
            app.UIFigure = uifigure;
            app.UIFigure.Position = [100 100 811 480];
            app.UIFigure.Name = 'UI Figure';

            % Create ALGORITMGMenu
            app.ALGORITMGMenu = uimenu(app.UIFigure);
            app.ALGORITMGMenu.MenuSelectedFcn = createCallbackFcn(app, @ALGORITMGMenuSelected, true);
            app.ALGORITMGMenu.Text = 'ALGORITM G';

            % Create ALGORITMGPPMenu
            app.ALGORITMGPPMenu = uimenu(app.UIFigure);
            app.ALGORITMGPPMenu.Text = 'ALGORITM GPP';

            % Create ALGORITMGPCMenu
            app.ALGORITMGPCMenu = uimenu(app.UIFigure);
            app.ALGORITMGPCMenu.Text = 'ALGORITM GPC';

            % Create ALGORITMKaczmarzMenu
            app.ALGORITMKaczmarzMenu = uimenu(app.UIFigure);
            app.ALGORITMKaczmarzMenu.Text = 'ALGORITM Kaczmarz';

            % Create UITable
            app.UITable = uitable(app.UIFigure);
            app.UITable.ColumnName = {'Column 1'; 'Column 2'; 'Column 3'; 'Column 4'};
            app.UITable.RowName = {};
            app.UITable.Position = [16 119 326 324];

            % Create UIAxes
            app.UIAxes = uiaxes(app.UIFigure);
            title(app.UIAxes, 'Title')
            xlabel(app.UIAxes, 'X')
            ylabel(app.UIAxes, 'Y')
            app.UIAxes.Position = [374 119 417 324];
        end
    end

    methods (Access = public)

        % Construct app
        function app = tutorialApp

            % Create and configure components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end